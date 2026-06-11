#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DEG_120 (2.0 * M_PI / 3.0)
#define DEG_60 (M_PI / 3.0)


typedef struct point {
    float x, y;
    float a;
    int i;
    struct point* next;
} Point;

void koch_curve(Point *start, Point *end, const int n)
{
    if (end == NULL) return;

    if (start->i == n) {
        start = start->next;
        if (start == NULL) return;
        return koch_curve(start, start->next, n);
    }

//    printf("start %f %f %d, end %f %f %d\n", start->x, start->y, start->i, end->x, end->y, end->i);

    Point *p1 = new Point;
    Point *p2 = new Point;
    Point *p3 = new Point;

    float dx = end->x - start->x;
    float dy = end->y - start->y;
    float l = sqrt(dx * dx + dy * dy) / 3.0;

    start->next = p1;
    start->i++;
    p1->x = start->x + dx / 3.0;
    p1->y = start->y + dy / 3.0;
    p1->a = start->a + DEG_60;
    p1->i = start->i;
    p1->next = p2;
    p2->x = p1->x + l * cos(p1->a);
    p2->y = p1->y + l * sin(p1->a);
    p2->a = p1->a - DEG_120;
    p2->i = start->i;
    p2->next = p3;
    p3->x = start->x + 2.0 * dx / 3.0;
    p3->y = start->y + 2.0 * dy / 3.0;
    p3->a = start->a;
    p3->i = start->i;
    p3->next = end;

/*
    Point* curr = start;
    while (1) {
        if (curr == end) break;
        printf("  %f %f\n", curr->x, curr->y);
        curr = curr->next;
    }
*/

    return koch_curve(start, start->next, n);
}


int main (void) {

    int n;
    Point start;
    Point end;

    start.x = 0.0;
    start.y = 0.0;
    start.a = 0.0;
    start.i = 0;
    start.next = &end;
    end.x = 100.0;
    end.y = 0.0;
    end.a = 0.0;
    end.i = 0;
    end.next = NULL;

    scanf("%d", &n);

    koch_curve(&start, &end, n);

    Point* curr = &start;
    while (1) {
        if (curr == NULL) {
            break;
        }
        printf("%f %f\n", curr->x, curr->y);
        curr = curr->next;
    }
}


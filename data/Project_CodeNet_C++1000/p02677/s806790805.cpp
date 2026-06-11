#include<stdio.h>
#include<math.h>
#define PI acos(-1.0)

int main()
{
    int A, B, H, M;
    double deg1, deg2, deg, dist;

    scanf("%d %d %d %d", &A, &B, &H, &M);

    deg1 = 30*(double)H + 0.5*(double)M;
    deg2 = 30*(double)M/5;
    deg = deg1 - deg2;
    deg = PI/180 * deg;

    dist = sqrt((double)A*(double)A + (double)B*(double)B - cos(deg)*2*(double)A*(double)B);

    printf("%.20lf", dist);

    return 0;
}
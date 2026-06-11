#include <stdio.h>

int x,y;
float c,t;

int main() {

    scanf("%d %d", &x, &y);
    c = (x*4.0-y) / 2.0;
    t = x - c;
    //printf("%f-%f", c, t);
    if (int(c)==c && int(t)==t && c>=0 && t>=0) {
        printf("Yes");
    }
    else {
        printf("No");
    }

    return 0;
}
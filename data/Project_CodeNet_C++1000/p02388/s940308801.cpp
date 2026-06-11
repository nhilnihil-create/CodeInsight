//Write a program which calculates the cube of a given integer x.
extern "C"
{
#include <stdio.h>

#define CUBIC   (3)

    int calc(const int x, const int num);

    int main(void)
    {
        int x;
        int ans = 0;
        scanf("%d", &x);

        ans = calc(x, CUBIC);

        printf("%d\n", ans);

        return (0);
    }

    //Calc a cubic of x.
    int calc(const int x, const int num)
    {
        if (1 > num) {
            return 1;
        }

        return x * calc(x, (num - 1));
    }
}
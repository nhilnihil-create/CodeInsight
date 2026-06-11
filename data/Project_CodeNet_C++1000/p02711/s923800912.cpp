#include<stdio.h>
 
int main()
{
    int input, angka1, angka2, angka3;
    scanf("%d", &input);
    angka1 = input / 100;
    angka2 = input % 100 / 10;
    angka3 = input % 10;
    if(angka1 == 7 || angka2 == 7 || angka3 == 7)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}
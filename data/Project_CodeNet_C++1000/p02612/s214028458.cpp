#include<cstdio>
#include<cstring>

const int constant = 1000;
int main()
{
    int n;
    scanf("%d", &n);
    if(n%constant==0)
        printf("0");
    else
        printf("%d", (n / constant + 1) * constant - n);
    return 0;
}

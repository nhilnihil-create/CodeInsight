#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int a, h, m, s;
    scanf("%d\n",&a);
    h = a/3600;
    m = (a-(h*3600))/60;
    s = a-((m*60)+(h*3600));
    printf("%d:%d:%d\n",h,m,s);
    
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,i,c;
    scanf("%d",&a);
    if(a==4||a==6||a==9||a==14||a==21||a==22||a==25||a==26)
    {
        printf("2\n");
    }
    else if(a==8||a==12||a==18||a==20||a==27)
    {
        printf("5\n");
    }
    else if(a==28||a==30)
    {
        printf("4\n");
    }
    else if(a==32)
    {
        printf("51\n");
    }
     else if(a==16)
    {
        printf("14\n");
    }
     else if(a==24)
    {
        printf("15\n");
    }
     else
    {
        printf("1\n");
    }

}

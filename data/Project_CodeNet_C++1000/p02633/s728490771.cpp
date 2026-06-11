#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
inline int gcd(int x,int y)
{
    if(y==0) return x;
    return gcd(y,x%y);
}
int main()
{
    int x;
    scanf("%d",&x);
    printf("%d\n",360/gcd(x,360));
    return 0;
}

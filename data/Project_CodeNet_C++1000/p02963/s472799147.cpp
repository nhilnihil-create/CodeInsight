#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cmath>
using namespace std;
#define ll long long
#define db double

int main()
{
    ll x1=0,y1=0;
    ll x3=1000000000;
    ll x2=1,y2=0,y3=0;
    ll s;
    scanf("%lld",&s);
    y2=(s/x3)+1;
    if(y2>1000000000)y2=1000000000;
    y3=y2*x3-s;
    printf("%lld %lld %lld %lld %lld %lld",x1,y1,x2,y2,x3,y3);
    return 0;
}

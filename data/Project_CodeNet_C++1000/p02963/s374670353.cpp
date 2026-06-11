#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
#define db double
int main()
{
    ll s=0;
    scanf("%lld",&s);
    ll x1=0;
    ll y1=0;
    ll x2=1;
    ll y2=1e9;
    ll x3=s/y2+(s%y2!=0);
    ll y3=y2*x3-s;
    printf("%lld %lld %lld %lld %lld %lld",x1,y1,x2,y2,x3,y3);
    return 0;
}


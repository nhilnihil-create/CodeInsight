#include<iostream>
#include<cstdio>
#include <stdio.h>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<vector>
#include <set>
#define ll long long
#define IO ios::sync_with_stdio(false);cin.tie();cout.tie(0)
#define inf 0x3f3f3f3f
using namespace std;
int a[100010];
int b[100010];
int c[500010];
int x,y;
int A,B,C;
int cmp(int a,int b)
{
    return a>b;
}
int main()
{
    cin>>x>>y>>A>>B>>C;
    for(int i=0;i<A;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<B;i++)
    {
        cin>>b[i];
    }
    for(int i=0;i<C;i++)
    {
        cin>>c[i];
    }
    sort(a,a+A,cmp);
    sort(b,b+B,cmp);
    for(int i=0;i<x;i++)
    {
        c[i+C]=a[i];
    }
    for(int i=0;i<y;i++)
    {
        c[i+C+x]=b[i];
    }
    sort(c,c+C+x+y,cmp);
    ll sum=0;
    for(int i=0;i<x+y;i++)
    {
        sum+=c[i];
    }
    cout<<sum<<endl;
    return 0;
}

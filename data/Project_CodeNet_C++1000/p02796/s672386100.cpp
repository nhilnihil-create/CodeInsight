#include<iostream>
#include<cstdio>
#include <stdio.h>
#include<algorithm>
#include<cstring>
#include <string>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<vector>
#include<bits/stdc++.h>
#include <set>
#define ll   long long
#define IO ios::sync_with_stdio(false);cin.tie();cout.tie(0)
#define inf 0x3f3f3f
#define pi 3.1415926535898
using namespace std;
ll m,n;
const int N=3e5+10;
struct A
{
    int l,r;
}a[N];
int cmp(A a,A b)
{
    return a.l<b.l;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        a[i].l=x-y;
        a[i].r=x+y;
    }
    sort(a,a+n,cmp);
    int now=-1e9;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(a[i].l>=now)
        {
            now=a[i].r;
            ans++;
        }
        else
        {
            now=min(a[i].r,now);
        }
    }
    cout<<ans<<endl;
    return 0;
}

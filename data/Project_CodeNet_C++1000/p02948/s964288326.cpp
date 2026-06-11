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
const int N=2e5+10;
struct A
{
    int t,w;
} a[N];
int cmp(A a,A b)
{
    return a.t<b.t;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        cin>>a[i].t>>a[i].w;
    }
    sort(a,a+n,cmp);
    priority_queue <int>q;
    ll ans=0;
    int id=0;
    for(int i=1; i<=m; i++)
    {
        while(a[id].t<=i&&id<n)
        {
            q.push(a[id].w);
            id++;
        }
        if(q.empty())
            continue;
        ans += q.top();
        q.pop();

    }
    cout<<ans<<endl;
    return 0;
}

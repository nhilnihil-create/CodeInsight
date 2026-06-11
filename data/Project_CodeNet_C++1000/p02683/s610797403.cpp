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
#define inf 0x3f3f3f3f
#define pi 3.1415926535898
using namespace std;
ll n,m,x;
ll a[100][100];
ll c[100];
int main()
{
    ll sum=inf;
    cin>>n>>m>>x;
    for(int i=0; i<n; i++)
    {
        cin>>c[i];
        for(int j=0; j<m; j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<(1<<n);i++)
    {
        ll ans=0;
        int k[100];
        memset(k,0,sizeof(k));
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))
            {
                ans+=c[j];
                for(int y=0;y<m;y++)

                {
                    k[y]+=a[j][y];
                }
            }
        }
        int t=1;
        for(int j=0;j<m;j++)
        {
            if(k[j]<x)
            {
                t=0;
                break;
            }
        }
        if(t==1)
        {
            sum=min(sum,ans);
        }
    }
    if(sum==inf)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<sum<<endl;
    }

    return 0;
}

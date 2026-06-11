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
vector <int>g[16][2];
int n;
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        for(int j=0; j<x; j++)
        {
            int a,b;
            cin>>a>>b;
            g[i][b].push_back(a);
        }
    }
    int ans=0;
    for(int i=0; i<(1<<n); i++)
    {
        bool flag=true;
        for(int y=1; y<=n; y++)
        {
            bool f=true;
            for(int k=0; k<g[y][0].size(); k++)
                if(1<<(g[y][0][k]-1)&i)
                    f=false;
            for(int k=0; k<g[y][1].size(); k++)
                if(!((1<<g[y][1][k]-1)&i))
                    f=false;
            if(f&&(!(1<<(y-1)&i)))
                flag=false;
            if(!f&&(1<<(y-1)&i))
                flag=false;
        }
        if(flag)
            ans=max(ans,__builtin_popcount(i));
    }
    cout<<ans<<endl;
    return 0;
}

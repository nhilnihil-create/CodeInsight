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
const int N=1e3+100;
int a[N][N],top[N],vis[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        top[i]=1;
        for(int j=1; j<=n-1; j++)
        {
            cin>>a[i][j];
        }
    }
    int cnt=1;
    while(1)
    {
        int f=0;
        for(int i=1;i<=n;i++)//模拟N天
        {
            if(top[i]>=n||vis[i]==cnt)
                continue;
            int v=a[i][top[i]];
            if(vis[v]!=cnt && top[v]<n && a[v][top[v]]==i)
            {
                top[v]++; top[i]++;
				vis[i]=vis[v]=cnt;
				f=1;

            }
        }
        if(f==0)
        {
            break;
        }
        cnt++;
    }
    for(int i=1;i<=n;i++)
    {
        if(top[i]!=n)
        {
            cout<<-1;
            return 0;
        }
    }
    cout<<cnt-1;
    return 0;
}

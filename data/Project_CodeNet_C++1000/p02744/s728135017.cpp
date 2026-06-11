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
#define inf 0x3f3f3f3f3f3f3f3f
#define pi 3.1415926535898
#define N 200010
using namespace std;
int n;
int a[15];
void dfs(int x,int p)
{
    int j,i,now;
    if(x==n)
    {
        for(j=0; j<n; j++)
            printf("%c",a[j]+'a');
        printf("\n");
        return ;
    }
    now=min(x,p+1);
    for( i=0; i<=now; i++)
    {
        a[x]=i;
        p=max(p,i);
        dfs(x+1,p);
    }
}
int main()
{
    scanf("%d",&n);
    dfs(0,-1);
    return 0;
}

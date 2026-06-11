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
#define ll  unsigned long long
#define IO ios::sync_with_stdio(false);cin.tie();cout.tie(0)
#define inf 0x3f3f3f3f
#define pi 3.1415926535898
using namespace std;
ll  a[100010],b[100010],c[100010];
ll  n;
ll  ans=0;
int main()
{

    cin>>n;
    n++;
    for(long long int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    b[1]=1,c[n]=a[n];
    for(long long int i=2;i<=n;i++)
    {
        b[i]=(b[i-1]-a[i-1])*2;
    }
    for(long long int i=n-1;i>=1;i--)
    {
        c[i]=c[i+1]+a[i];
    }
    for(long long int i=1;i<=n;i++)
    {
        ans+=min(b[i],c[i]);
    }
    for(long long int i=1;i<=n;i++)
    {
        if(a[i]>b[i])
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
    return 0;
}

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
ll n,k;
ll ans;
char a[100050];
int main()
{
    cin>>n>>k;
    cin>>a+1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]=='L'&&a[i-1]=='L')
        {
            ans++;
        }
    }
    for(int i=n;i>=1;i--)
    {
        if(a[i]=='R'&&a[i+1]=='R')
        {
            ans++;
        }
    }
    ans=min(n-1,ans+2*k);
    cout<<ans<<endl;
    return 0;
}

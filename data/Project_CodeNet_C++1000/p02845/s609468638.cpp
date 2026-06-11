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
const int mod=1e9+7;
int a[100010];
int k[4];
int main()
{
    int x,n;
    cin>>n;
    ll ans=1;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for(int i=1; i<=n; i++)
    {
        ll sum=0;
        for(int j = 1; j <= 3; ++j)
        {
            if(k[j] == a[i])
                sum++;
        }
        ans=ans*sum%mod;
        for(int j = 1; j <= 3; ++j)
        {
            if(k[j] == a[i])
            {
                k[j]++;
                break;
            }
        }
    }
    cout<<(ans+mod)%mod;
    return 0;
}

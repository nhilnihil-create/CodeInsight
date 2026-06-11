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
#define mod 998244353
#define N 1000010
using namespace std;
map <int ,int > mp;
int main()
{
    int n,k;
    cin>>n;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        int t=-k-i;
        mp[t]++;
        if(mp.count(k-i))
        {
            ans+=(ll)mp[k-i];
        }

    }
    cout<<ans<<endl;
    return 0;
}

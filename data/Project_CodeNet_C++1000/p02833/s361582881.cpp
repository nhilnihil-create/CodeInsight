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
const int N=1e5+10;
const int mod=1e9+7;

int main()
{
    ll x;
    cin>>x;
    ll ans=0;
    if(x%2==1)
    {
        cout<<0<<endl;
    }
    else
    {
        x=x/2;
        while(x>=5)
        {
            x=x/5;
            ans+=x;
        }
        cout<<ans<<endl;
    }
    return 0;
}

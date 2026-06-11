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
const int mod=998244353;
const int N=2e5+10;

ll gcd(ll a,ll b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);

}
int main()
{
    ll x,y;
    cin>>x>>y;
    ll g=gcd(x,y);
    ll cnt=1;
    for(ll i=2; i*i<=g; i++)
    {
        if(g%i==0)
            cnt++;
        while(g%i==0)
        {
            g=g/i;
        }
    }
    if(g>1)
    {
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}

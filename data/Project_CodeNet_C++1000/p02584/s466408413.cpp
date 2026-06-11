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
const int N=2e5+10;
const int mod=1e9+7;
ll n,k,d;
int main()
{
    cin>>n>>k>>d;
    n=abs(n);
    ll sum=n/d;
    ll t=n%d;
    if(sum>k)
    {
        cout<<n-k*d<<endl;
    }
    else
    {
        int x=k-sum;
        if(x%2==0)
        {
            cout<<n%d<<endl;
        }
        else
        {
            cout<<d-n%d<<endl;
        }
    }
    return 0;
}

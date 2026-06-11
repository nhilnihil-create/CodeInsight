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

int main()
{
    ll a1,a2,t1,t2,b1,b2;
    cin>>t1>>t2>>a1>>a2>>b1>>b2;
    if(a1*t1+a2*t2 == b1*t1+b2*t2)
    {
        cout<<"infinity"<<endl;
        return 0;
    }
    a1=a1*t1;
    a2=a2*t2;
    b1=b1*t1;
    b2=b2*t2;
    if(a1+a2>b1+b2)
    {
        swap(a1,b1);
        swap(a2,b2);
    }
    if(a1>b1)
    {
        ll r = (a1-b1)/(b1+b2-a1-a2);
        ll res = 2*r;
        if((a1-b1)%(b1+b2-a1-a2))
            res++;
        cout<<res<<endl;
    }
    else
    {
        cout<<0<<endl;
    }
    return 0;
}

#include<iostream>
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
ll w, h, x, y ;
int main()
{
    IO
    cin>>w>>h>>x>>y;
    cout<<fixed<<setprecision(10)<<(1.0*w*h/2.0)<<" ";
    if((w%2==0 && x==w/2)&& (h%2==0 && y==h/2))
        cout<<1;
    else
        cout<<0;
}

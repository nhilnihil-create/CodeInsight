#include<iostream>
//#include <cmath>
//#include <bits/stdc++.h>

typedef long double ld;

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
  //  freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ld w,h,x,y;cin>>w>>h>>x>>y;
    //cout<<max(min(x,w-x)*h,min(y,h-y)*w)<<" ";
    cout<<w*h/2<<" ";
    if(x==w/2&&y==h/2) cout<<1;
    else cout<<0;
    return 0;
}
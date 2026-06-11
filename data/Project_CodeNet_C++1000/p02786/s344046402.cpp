#include <iostream>
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

using namespace std;

ll f(ll h){
    if(h==1) return 1;
    ll a =f(h/2);
    return 2*a+1;
}

int main()
{
    ll h;
    cin>>h;
    cout<<f(h)<<endl;
   return 0;
}
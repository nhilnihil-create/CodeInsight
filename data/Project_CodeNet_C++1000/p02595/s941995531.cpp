#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n,d;
    cin>>n>>d;
    ll c=0;
    while(n--){
        ll x,y;
        cin>>x>>y;
        ll w = x*x + y*y;
        if(w <= d*d)
        c++;
    }
    cout<<c;
}
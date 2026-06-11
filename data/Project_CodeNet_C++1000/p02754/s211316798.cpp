#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    ll n, a, b;
    cin>>n>>a>>b;
    ll ans = 0;
    ll g = a+b;
    ll d = n/g;
    ans += a*d;
    n -= d*g;
    ans += min(n, a);
    cout<<ans;
    return 0;
}
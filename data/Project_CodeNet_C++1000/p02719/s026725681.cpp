#include<bits/stdc++.h>

#define Bye return 0
#define ll long long

using namespace std;

void solve(){
    ll n, k, res, x; cin>>n>>k;
    x = n/k;
    res = min(n, min(abs(n - x*k), abs(n - (x+1)*k)));
    cout<<res<<endl;
}

int main(){
    solve();
    Bye;
}
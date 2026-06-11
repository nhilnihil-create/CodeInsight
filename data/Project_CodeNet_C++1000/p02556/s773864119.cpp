#include<bits/stdc++.h>

#define Bye return 0
#define ll long long

using namespace std;

const int M = 1e9+7;

void solve(){
    int n; cin>>n;

    vector<ll> pos(n), neg(n);
    for (int i=0; i<n; i++){
        ll x, y; cin>>x>>y;
        pos[i] = x + y;
        neg[i] = x - y;
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    cout<<(max(pos[n-1]-pos[0], neg[n-1]-neg[0]));
}
int main(){
    solve();
    Bye;
}
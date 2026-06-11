#include<bits/stdc++.h>

#define CodeTyper main
#define Bye return 0
#define ll long long

using namespace std;

void solve(){
    ll n, k, q; cin>>n>>k>>q;

    vector<ll> players(n, k);
    for (ll i=0; i<q; i++){
        ll e; cin>>e;
        players[e-1]++;
    }
    for (ll i=0; i<n; i++)
        cout<<(players[i]-q<=0 ? "No" : "Yes")<<endl;
}

int CodeTyper(){
    solve();
    Bye;
}
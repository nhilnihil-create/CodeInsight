#include<bits/stdc++.h>
#define Bye return 0
#define ll long long

using namespace std;

void solve(){
    ll n, m, x; cin>>n>>m>>x;
    ll price[n];
    ll level[n][m];
    for (ll i=0; i<n; i++){
        cin>>price[i];
        for (ll j=0; j<m; j++)
            cin>>level[i][j];
    }

    ll minimum = LONG_LONG_MAX;
    for (ll i=1; i<(1<<n); i++){

        vector<ll> understand(m);
        ll payment = 0;
        for (ll j=0; j<n; j++){
            if(i & (1<<j)){
                payment += price[j];
                for (ll x=0; x<m; x++)
                    understand[x] += level[j][x];
            }
        }

        ll counter = 0;
        for (ll j=0; j<m; j++)
            counter += (understand[j]>=x);
        
        if(counter == m) minimum = min(minimum, payment);
    }

    cout<<(minimum^LONG_LONG_MAX ? minimum: -1)<<endl;
}

int main(){
    solve();
    Bye;
}
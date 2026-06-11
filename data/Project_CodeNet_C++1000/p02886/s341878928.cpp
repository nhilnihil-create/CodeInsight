#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i = 0; i < (ll) n; i++)
#define xrep(i,x,n) for(ll i = (ll) x; i < (ll) n; i++)
#define vll vector<long long>
#define vs vector<string>

int main() {
    ll N; cin >> N;
    vll d(N);
    rep(i,N) cin >> d[i];

    ll sum = 0;
    rep(i,N){
        xrep(j,i+1,N){
            sum += (d[i] * d[j]);
        }
    }

    cout << sum << endl;
}
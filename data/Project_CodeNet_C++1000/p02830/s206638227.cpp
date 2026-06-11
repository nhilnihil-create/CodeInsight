#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i = 0; i < (ll) n; i++)
#define xrep(i,x,n) for(ll i = (ll) x; i < (ll) n; i++)
#define vl vector<long long>
#define vs vector<string>

int main() {
    ll N; cin >> N;
    string S,T,U; cin >> S >> T;

    rep(i,N){
        U = U + S[i] + T[i];
    }
    cout << U << endl;
}
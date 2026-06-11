#include <bits/stdc++.h>          
using namespace std;       
typedef long long ll;        

int main() {
    ll N,M;
    cin >> N >> M;
    vector<ll> A(M);
    for (ll i=0; i<M; i++) {
        cin >> A.at(i);
    }
    ll day = 0;
    for (ll i=0; i<M; i++) {
        day += A.at(i);
    }
    if (day>N) {
        cout << -1 << endl;
    }
    else {
        cout << N-day <<endl;
    }
}
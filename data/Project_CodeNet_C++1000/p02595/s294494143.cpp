#include <bits/stdc++.h>          
using namespace std;            
typedef long long ll;   

int main() {
    ll N, D;
    cin >> N >> D;
    D *= D;
    vector<ll> X(N), Y(N);
    for (ll i=0; i<N; i++) {
        cin >> X[i] >> Y[i];
        X[i] *= X[i];
        Y[i] *= Y[i];
    }
    ll count = 0;
    for (ll i=0; i<N; i++) {
        ll d = X[i] + Y[i];
        if (d <= D) {
            count++;
        }
    }
    cout << count << endl;
}
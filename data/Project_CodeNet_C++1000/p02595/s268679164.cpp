#include <bits/stdc++.h>          
using namespace std;  
typedef long long ll;             

int main() {
    ll N, D;
    cin >> N >> D;
    vector<ll> X(N);
    vector<ll> Y(N);
    for (ll i=0; i<N; i++) {
        cin >> X.at(i) >> Y.at(i);
    }
    vector<ll> L(N);
    for (ll i=0; i<N; i++) {
        L.at(i) = pow(X.at(i),2) + pow(Y.at(i),2);
    }
    ll count = 0;
    for (ll i=0; i<N; i++) {
        if(pow(D,2)>=L.at(i)) {
            count++;
        }
    }
    cout << count << endl;
}
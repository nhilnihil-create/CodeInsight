#include <bits/stdc++.h>          
using namespace std;               
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    A.at(0) = 1;
    for (ll i=0; i<N-1; i++) {
        cin >> A.at(i+1);
    }

    vector<ll> B(N);
    for (ll i=0; i<N; i++) {
        B.at(A.at(i)-1)++;
    }
    B.at(0)--;

    for (ll i =0; i<N; i++) {
        cout << B.at(i) <<endl;
    }
}
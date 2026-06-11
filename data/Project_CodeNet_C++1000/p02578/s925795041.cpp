#include <bits/stdc++.h>          
using namespace std;     
typedef long long ll;             

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (ll i=0; i<N; i++) {
        cin >> A[i];
    }
    ll count = 0;
    for (ll i=1; i<N; i++) {
        if (A[i]<A[i-1]) {
            count += A[i-1]-A[i];
            A[i] = A[i-1];
        }
    }
    cout << count << endl;
}
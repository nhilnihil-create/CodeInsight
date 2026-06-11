#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll K, N;
    cin >> K >> N;

    ll A[N], d[N];
    for(ll i = 0; i < N; i++) {
        cin >> A[i];
        if(i >= 1) {
            d[i] = A[i] - A[i - 1];
        }
    }
    d[0] = (K - A[N - 1]) + A[0];

    ll max = d[0];
    for(ll i = 1; i < N; i++) {
        if(max < d[i]) {
            max = d[i];
        }
    }
    cout << K - max << endl;
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    sort(A.begin(),A.end());

    if(K >= N) {
        cout << 0 << endl;
        return 0;
    }

    for(int i=0; i<K; i++) {
        A.pop_back();
    }
    ll sum = 0;
    for(int i=0; i<A.size(); i++) {
        sum += A[i];
    }
    cout << sum << endl;
}
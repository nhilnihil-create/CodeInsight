#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll N, M, ac=0, penalty=0; cin >> N >> M;
    vector<bool> A(N, false);
    vector<ll> B(N, 0);
    ll p; string S;
    for (int i=0; i<M; ++i){
        cin >> p >> S; p--;
        if (S=="WA") B[p]++;
        else {
            if (A[p]) continue;
            ac++;
            penalty += B[p];
            A[p] = true;
        }
    }
    cout << ac << " " << penalty << endl;
    return 0;
}
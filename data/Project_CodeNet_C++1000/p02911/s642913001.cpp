#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> A(Q), AC(N);
    rep(i,Q) cin >> A.at(i);
    rep(i,Q) ++AC.at(A.at(i) - 1);
    rep(i,N) {
        if (AC.at(i) + K - Q > 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}

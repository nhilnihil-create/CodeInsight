#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) {
        cin >> A[i];
    }

    ll ans = 0;
    int mx = A[0];

    for (int i=1; i<N; i++) {
        if (A[i] < mx) {
            ans += mx - A[i];
        } else {
            mx = A[i];
        }
    }
    
    cout << ans << endl;
    return 0;
}
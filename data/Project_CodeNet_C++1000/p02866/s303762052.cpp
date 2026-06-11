#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;
const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> D(N);
    for (int i=0;i<N;i++){
        cin >> D[i];
    }
    if (D[0] != 0) {
        cout << 0 << "\n";
        return 0;
    }
    for (int i=1;i<N;i++){
        if (D[i] <= 0) {
            cout << 0 << "\n";
            return 0;
        }
    }
    vector<int> num(N);
    int mx = 0;
    for (int i=0;i<N;i++) {
        num[D[i]]++;
        if (D[i] > mx) mx = D[i];
    }
    ll ans = 1;
    for (int i=1;i<=mx;i++){
        for (int j=0;j<num[i];j++){
            ans *= num[i-1];
            ans %= MOD;
        }
    }
    cout << ans << "\n";
}
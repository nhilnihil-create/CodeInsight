#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<ll> A(N+1);
    for (int i=0;i<=N;i++) cin >> A[i];
    vector<ll> sum(N+2);
    for (int i=N+1;i>=1;i--) sum[i-1] = sum[i] + A[i-1];
    ll Lmax = 1;
    ll ans = 0;
    for (int i=0;i<=N;i++){
        if (A[i] > Lmax) {
            cout << -1 << "\n";
            return 0;
        } else {
            ans += Lmax;
            Lmax = (Lmax-A[i])*2;
            Lmax = min(Lmax,sum[i+1]);
        }
    }
    cout << ans << "\n";
}
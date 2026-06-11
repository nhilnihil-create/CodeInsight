#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;

int main() {
    int N, K; cin >> N >> K;
    vector<int> P(N), C(N);
    for (int i = 0; i < N; i++) { cin >> P[i]; P[i]--; }
    for (int i = 0; i < N; i++) cin >> C[i];
    
    ll ans = -INF;
    for (int i = 0; i < N; i++) {
        int x = i;
        vector<int> S;
        ll sum = 0;
        while (true) {
            x = P[x];
            S.push_back(C[x]);
            sum += C[x];
            if (x == i) break;
        }
        int n = S.size();
        ll t = 0;
        for (int j = 0; j < n; j++) {
            t += S[j];
            if (j + 1 > K) break;
            ll now = t; 
            if (sum > 0) {
                ll cnt = (K - (j + 1) ) / n;
                now += sum * cnt;
            }
            ans = max(ans, now);
        }
    }
    cout << ans << endl;
    return 0;
}
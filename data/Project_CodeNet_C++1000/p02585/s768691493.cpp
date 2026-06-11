#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)

using ll = long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

int main() {
    int N, K;
    cin >> N >> K;
    V<int> P(N), C(N);
    rep(i, N) cin >> P[i], --P[i];
    rep(i, N) cin >> C[i];
    
    ll ans = -1000000000;
 
    rep(i, N) {
        int v = i;
        ll cycle_sum = 0;
        int cycle_cnt = 0;
 
        while (true) {
            cycle_cnt++;
            cycle_sum += C[v];
            v = P[v];
            if (v == i) break;
        }
 
        ll path = 0;
        int cnt = 0;
 
        while (true) {
            cnt++;
            path += C[v];
 
            if (cnt > K) break;
            int num = (K - cnt) / cycle_cnt;
            ll score = path + max(0ll,cycle_sum) * num;
            if(ans<score)ans = score;
 
            v = P[v];
            if (v == i) break;
        }
    }
 
    cout << ans << endl;
 
    return 0;
}
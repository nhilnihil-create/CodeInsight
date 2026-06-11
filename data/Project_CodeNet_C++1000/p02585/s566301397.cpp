#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;


int N_MAX = 5010;
int n, k;
vector<ll> P(N_MAX), C(N_MAX);

ll solve() {
    ll res = -INF;
    // サイクルに分ける
    vector<vector<ll>> cycle;
    vector<bool> used(n+10, false);
    rp(i, 0, n) {
        if(used[i]) continue;
        int cur = i;
        vector<ll> s;
        while(1) {
            if(used[cur]) break;
            used[cur] = true;
            s.push_back(C[cur]);
            cur = P[cur];
        }
        cycle.push_back(s);
    }

    // サイクルごとに考える
    for(auto x:cycle) {
        ll M = x.size();  // サイクルの大きさ
        ll sum = 0ll;  // サイクル一周の得点
        for(auto y: x) sum+=y;
        vector<ll> Cum(2*M);  // 累積和
        Cum[0] = x[0];
        rp(i, 1, 2*M) {
            Cum[i] = Cum[i-1] + x[i%M];
        }
        rp(r, 1, M+1) {  // 余りを固定 余りは1~M
            if(r > k) continue;
            rp(m, 0, M){  // 何番目から取り始めるか
                ll temp = Cum[m+r] - Cum[m];
                if(sum > 0) temp += ((k-r) / M) * sum;
                chmax(res, temp);
            }  
        }
    }
    return res;
}

int main() {
    cin >> n >> k;
    rp(i, 0, n) {
        ll p; cin >> p; p--; P[i] = p;
    }
    rp(i, 0, n) {
        ll c; cin >> c; C[i] = c;
    }
    cout << solve() << endl;
}
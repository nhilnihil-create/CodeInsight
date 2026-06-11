#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<ll> makeDivisors(ll n) {
    vector<ll> ret;
    for(ll i = 1; i * i <= n; i++) {
        if(n%i == 0) {
            ret.push_back(i);
            if(i*i != n) ret.push_back(n/i);
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N+1);
    rep(i, N) cin >> A[i+1];
    vector<int> cnt(N+1, 0);
    vector<int> B(N+1, 0);
    vector<int> ans;
    for (int i = N; i >= 1; i--) {
        if (A[i] ^ cnt[i]) {
            B[i] = 1;
        }
        if (B[i]) {
            ans.push_back(i);
            vector<ll> C = makeDivisors(i);
            for (int c : C) {
                if (c == i) continue;
                cnt[c] ^= 1;
            }
        }
    }
    cout << sz(ans) << '\n';
    show(ans);
    return 0;
}
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i ++)
#define irep(i,n) for (int i = (int)(n) - 1;i >= 0;--i)
using namespace std;
using ll = long long;
using PL = pair<ll,ll>;
using P = pair<int,int>;
constexpr int INF = 1000000000;
constexpr long long HINF = 1000000000000000;
constexpr long long MOD = 1000000007;// = 998244353;
constexpr double EPS = 1e-4;
constexpr double PI = 3.14159265358979;

int main() {
    int N; cin >> N;
    vector<ll> S(1<<N);
    rep(i,1<<N) cin >> S[i];

    priority_queue<ll,vector<ll>> q,next;
    multiset<ll> left;
    ll M = -1;
    rep(i,1<<N) {
        if (M < S[i]) {
            if (M > 0) left.insert(M);
            M = S[i];
        } else {
            left.insert(S[i]);
        }
    }
    q.push(M);
    bool flag = true;
    rep(i,N) {
        while (!q.empty()) {
            ll x = q.top(); q.pop();
            auto itr = left.lower_bound(x);
            if (itr == left.begin()) {
                flag = false;
                break;
            }
            --itr;
            next.push(x);
            next.push(*itr);
            left.erase(itr);
        }
        if (!flag) break;
        swap(q,next);
    }
    if (flag) cout << "Yes" << '\n';
    else cout << "No" << '\n';
    return 0;
}
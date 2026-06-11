#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;

vector<ll> divisor(int n) {
    vector<ll> res;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) {
                res.push_back(n / i);
            }
        }
    }

    return res;
}

int main()
{
    int N;
    cin >> N;
    vector<int> A(N + 1), cnt(N + 1);
    rep(i, N) cin >> A[i + 1];

    vector<int> ans;
    for (int i = N; i > 0; i--) {
        if ((cnt[i] % 2) != A[i]) {
            cnt[i]++;
            ans.push_back(i);
            vector<ll> res = divisor(i);
            rep(j, res.size()) {
                cnt[res[j]]++;
            }
        }
    }

    cout << (int)ans.size() << endl;
    rep(i, ans.size()) {
        cout << ans[i] << endl;
    }
    return 0;
}
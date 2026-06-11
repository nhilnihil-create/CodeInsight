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

vector<ll> divisor(ll n) {
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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    ll sum = 0;
    rep(i, N) {
        cin >> A[i];
        sum += A[i];
    }

    vector<ll> res = divisor(sum);
    ll ans = 0;
    rep(i, res.size()) {
        vector<ll> mod;
        rep(j, N) {
            if (A[j] % res[i]) mod.push_back(A[j] % res[i]);
        }
        sort(all(mod));
        repd(j, 1, mod.size()) {
            mod[j] += mod[j - 1];
        }
        bool flag = false;
        ll len = (ll)mod.size();
        rep(j, mod.size()) {
            // cout << res[i] << " " << mod[j] << ":" << j  << " " << res[i] * (len - j - 1) - (mod[len - 1] - mod[j]) << endl;
            if ((mod[j] == (res[i] * (len - j - 1) - (mod[len - 1] - mod[j]))) && mod[j] <= K) {
                flag = true;
                break;
            }
        }
        if (flag || len == 0) {
            chmax(ans, res[i]);
        }
    }

    cout << ans << endl;
    return 0;
}
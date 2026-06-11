#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    ll N, Pi; cin >> N >> Pi;
    string S; cin >> S;
    reverse(S.begin(), S.end());
    ll ans = 0;
    if(Pi == 5 || Pi == 2) {
        rep(i, N) {
            if((S[i] - '0') % Pi == 0) {
                ans += N - i;
            }
        }
    }else {
        ll mult10 = 1;
        ll dp[S.size() + 1]; // 後ろからi桁を見たときのPで割った剰余
        map<ll, ll> m;
        m[0]++;
        dp[0] = 0;
        rep(i, S.size()) {
            dp[i + 1] = (dp[i] + (S[i] - '0') * mult10) % Pi;
            m[dp[i + 1]]++;
            mult10 = mult10 * 10 % Pi;
        }
        for(auto i = m.begin(); i != m.end(); ++i) ans += (i->second)*(i->second - 1)/2;
        rep(i, S.size()) {
            if(S[i] == '0') {

            }
        }
    }
    cout << ans << endl;
}

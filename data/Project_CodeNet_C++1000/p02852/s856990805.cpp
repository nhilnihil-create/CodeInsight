#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
template<class T> using vc = vector<T>;
template<class T> using vvc = vector<vector<T>>;

const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;
const ll INF = 1e16;
const ld EPS = 1e-11;
const ld PI = acos(-1.0L);
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, n) for (ll i = (n)-1; i >= 0; i--)
#define repe(i, l, r) for (ll i = (l); i < (r); i++)
#define reper(i, l, r) for (ll i = (r)-1; i >= (l); i--)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

void init() {cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(15);}
//--------------------------------------------------------------------------------//

int main() {
    init();
    ll N,M;
    cin >> N >> M;
    string S;
    cin >> S;
    
    ll now=N;
    vl ans;

    while(now>0){
        ll next = -1;
        repe(l,1,M+1){
            if (now - l < 0) break;
            if(S[now-l]=='0'){
                next = l;
            }
        }

        if (next == -1){
            cout << -1 << endl;
            return 0;
        }

        ans.eb(next);
        now -= next;
    }

    reverse(all(ans));
    rep(i, ans.size()) cout << ans[i] << " ";
    cout << endl;
}
#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;
typedef pair<ll, ll> P;

template<typename T>
void print(const vector<T> &x) {
    int n = x.size();
    rep(i,n) {
        cout << x[i];
        if (i!=n-1) cout<<" ";
        else cout << endl;
    }
}

template<typename T>
void print(const vector<vector<T>> &x) {
    int n = x.size();
    rep(i,n) {
        rep(j,x[i].size()) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}

template<typename T>
void print(const vector<T> &x, int n) {
    rep(i,n) {
        cout << x[i];
        if (i!=n-1) cout<<" ";
        else cout << endl;
    }
}

template<typename T>
void print(const vector<vector<T>> &x, int n, int m) {
    rep(i,n) {
        rep(j,m) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void input_init() {
    cin.tie(0); ios::sync_with_stdio(false);
}

int main(int argc, char const *argv[]) {
    ll n,k; cin>>n>>k;
    vector<ll> p(n),c(n);
    rep(i,n) cin>>p[i], --p[i];
    rep(i,n) cin>>c[i];
    /*tmp = 23514205912
    ans2 = 26453481651*/

    vector<ll> lc(n), lv(n);
    auto loop = [&] (ll idx) {
        ll goal = idx;
        ll cur = p[goal];
        ll s = c[cur];
        ll cnt = 1;
        while (cur != goal) {
            cur = p[cur];
            cnt++;
            s += c[cur];
        }
        lc[idx] = cnt;
        lv[idx] = s;
    };

    rep(i,n) loop(i);

    auto simu = [&] (ll idx, ll cnt, ll q) -> ll {
        ll ret = -LINF*2;
        ll tmp = q;
        ll cur = idx;
        while (cnt--) {
            cur = p[cur];
            tmp += c[cur];
            chmax(ret, tmp);
        }
        return ret;
    };

    ll ans = -LINF*2;
    if (k < 10000) {
        rep(i,n) {
            chmax(ans, simu(i,min(k,15000ll), 0ll));
        }
    }
    else {
        rep(i,n) {
            //cout << "i = " << i << '\n';
            //cout << "lv[i] = " << lv[i] << '\n';
            //cout << "lc[i] = " << lc[i] << '\n';
            ll v = lv[i];
            ll cnt = lc[i];
            if (v <= 0) {
                chmax(ans, simu(i, min(cnt, 10000ll), 0ll));
            }
            else {
                ll sho = k/cnt;
                ll yo = k%cnt;
                sho--;
                yo += cnt;
                ll tmp = 0;
                tmp += v*sho;
                if (chmax(ans, simu(i,yo,tmp))) {
                    //cout << "i = " << i << '\n';
                    //cout << "ans = " << ans << '\n';
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}

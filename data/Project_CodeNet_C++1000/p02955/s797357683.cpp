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
    ll sum = 0;
    vector<ll> a(n);
    rep(i,n) cin>>a[i], sum+=a[i];

    set<ll> div;
    for (int i = 1; i*i <= sum; ++i) {
        if (sum%i == 0) {
            div.insert(i); div.insert(sum/i);
        }
    }

    auto check = [&] () {
        ll ans = 0;
        for (auto &&e: div) {
            vector<ll> tmp,tnp;
            rep(i,n) {
                if (a[i]%e) {
                    tmp.push_back(a[i]%e);
                    tnp.push_back(e-(a[i]%e));
                }
            }

            sort(tmp.begin(), tmp.end());
            sort(tnp.begin(), tnp.end(), greater<>());
            vector<ll> smp(tmp.size()+1), snp(tnp.size()+1);
            rep(i,tmp.size()) smp[i+1] += smp[i]+tmp[i];
            for (int i = tnp.size(); i > 0; --i) snp[i-1] += snp[i]+tnp[i-1];

            rep(i,smp.size()) if (smp[i]==snp[i]) {
                if (smp[i] <= k) {
                    chmax(ans,e);
                    break;
                }
            }
        }
        return ans;
    };

    cout << check() << '\n';

    return 0;
}
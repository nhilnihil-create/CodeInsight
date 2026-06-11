#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;

int main() {
    int n, k; cin >> n >> k;
    int mx = (n-1)*(n-2)/2;
    if (k > mx) {cout << -1 << endl; return 0;}
    int ct = n-1;
    vector<P> ans;
    rep(i,n-1) ans.push_back(P(1,i+2));
    if (mx == k) {
        cout << ct << endl;
        rep(i,ans.size()) {
            cout << ans[i].first << " " << ans[i].second << endl;
        }
        return 0;
    } else {
        for (int i = 2; i < n; i++) {
            for (int j = i+1; j <= n; j++) {
                ans.push_back(P(i,j));
                mx--;
                ct++;
                if (mx == k) {
                    cout << ct << endl;
                    rep(i,ans.size()) {
                        cout << ans[i].first << " " << ans[i].second << endl;
                    }
                    return 0;
                }
            }
        }
    }
}
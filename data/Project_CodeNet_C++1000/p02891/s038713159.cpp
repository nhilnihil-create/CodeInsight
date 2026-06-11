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
const int inf = 1e9+7;
const ll inf_l = 1e18;
const int MAX = 1e6;

int main() {
    string s; cin >> s;
    int k; cin >> k;
    int ct = 1;
    int n = s.size();
    set<char> st;
    rep(i,n) st.insert(s[i]);
    if (st.size() == 1) {
        cout << (ll)n*k/2 << endl;
        return 0;
    }
    int n_1 = 0;
    rep(i,n-1) {
        if (s[i] == s[i+1]) ct++;
        else {
            n_1 += ct/2;
            ct = 1;
        }
    }
    n_1 += ct/2;
    ct = 1;
    int n_2 = 0;
    rep(i,2*n-1) {
        if (s[i%n] == s[(i+1)%n]) ct++;
        else {
            n_2 += ct/2;
            ct = 1;
        }
    }
    n_2 += ct/2;
    int diff = n_2 - n_1;
    ll ans = n_1 + (ll)diff*(k-1);
    cout << ans << endl;
}
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) {rep(i,x.size()) cout << x[i] << " "; cout << endl;}
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
const int MAX = 2e5;

vector<int> z_algorithm(string &s) {
    vector<int> res(s.size());
    res[0] = s.size();
    int i = 1, j = 0;
    while (i < (int)s.size()) {
        while (i+j < (int)s.size() && s[j] == s[i+j]) j++;
        res[i] = j;

        if (j == 0) {
            i++;
            continue;
        }
        int k = 1;
        while (k < j && k + res[k] < j) {
            res[i+k] = res[k];
            k++;
        }
        i += k;
        j -= k;
    }
    return res;
}

int main() {
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    rep(i,n) {
        string tmp = s.substr(i);
        vint x = z_algorithm(tmp);
        int mx = 0;
        rep(j,x.size()) {
            mx = max(mx,min(j,x[j]));
        }
        ans = max(ans,mx);
    }
    cout << ans << endl;
}
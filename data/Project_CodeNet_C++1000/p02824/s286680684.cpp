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

int n, m, v, p;
vint a;

bool check(int i) {
    int x = a[i] + m;
    if (x < a[p-1]) return false;
    ll y = (ll)(v-((p-1)+(n-i-1)+1))*m;
    if (y <= 0) return true;
    for (int j = p-1; j <= i-1; j++) {
        y -= x - a[j];
    }
    if (y <= 0) return true;
    else return false;
}

int main() {
    cin >> n >> m >> v >> p;
    a.assign(n+1,-inf);
    rep(i,n) cin >> a[i];
    sort(rall(a));
    int l = 0, r = n;
    while (r-l > 1) {
        int mid = (r+l)/2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l+1 << endl;
}
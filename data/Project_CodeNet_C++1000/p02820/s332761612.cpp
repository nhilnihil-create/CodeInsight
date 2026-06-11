#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int main(){
    int n, k, r, s, p;
    string t;
    cin >> n >> k >> r >> s >> p >> t;
    map<char, ll> mp;
    mp['r'] = p;
    mp['s'] = r;
    mp['p'] = s;
    ll ans = 0;
    VI cnts(n);
    rep(i,n){
        if (i - k < 0) {
            ans += mp[t[i]];
        }else{
            if (t[i] == t[i-k]){
                if (cnts[i-k] % 2 != 0) ans += mp[t[i]];
                cnts[i] = cnts[i-k] + 1;
            }else{
                ans += mp[t[i]];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
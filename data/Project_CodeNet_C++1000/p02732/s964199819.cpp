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

ll choose(ll n, ll r){
    ll res = 1;
    for(int i = 1; i <= r; i++){
        res *= n--;
        res /= i;
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    map<int, ll> mp;
    rep(i,n) mp[a[i]]++;
    ll sum = 0;
    for(auto m: mp){
        sum += choose(m.second, 2);
    }
    rep(i,n){
        ll ans = sum;
        ans -= choose(mp[a[i]], 2);
        ans += choose(mp[a[i]]-1, 2);
        cout << ans << endl;
    }
    return 0;
}
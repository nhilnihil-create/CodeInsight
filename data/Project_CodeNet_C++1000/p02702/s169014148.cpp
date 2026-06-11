#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define Rep(i,n) for(int i = 1; i <= n; i++)
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl '\n'
#define fi first
#define se second
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
template<class T> using V = vector<T>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
const int inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll &a, const ll &b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const int mod  = 2019;

int main(){
    
    string s;
    cin >> s;
    int n = sz(s);
    int ten = 1;
    V<int> a(n);
    for(int i = n-1; i >= 0; i--) {
        int c = s[i] - '0';
        a[i] = ten * c % mod;
        ten = ten * 10 % mod;
    }
    V<int> sum(n+1);
    sum[0] = 0;
    map<int, int> mp;
    mp[0]++;
    Rep(i,n) {
        sum[i] = (sum[i-1] + a[i-1]) % mod;
        mp[sum[i]]++;
    }

    ll ans = 0;
    for(P p : mp) {
        ans += p.se * (p.se-1) / 2;
    }
    cout << ans << endl;
}
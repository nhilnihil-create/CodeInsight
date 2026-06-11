#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
typedef long long ll;
typedef pair<ll,ll> prl;
typedef vector<ll> vcl;
typedef map<ll,ll> mapl;
typedef unordered_map<ll,ll> umap;
#define pb push_back
#define all(v) v.begin(), v.end()
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define repi(i,a,b) for(int i=a;i<=b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define reps(i,v) for(ll i=0;i<v.size();i++)
template<typename T> void chmin(T &a, const T &b) { a = min(a, b); }
template<typename T> void chmax(T &a, const T &b) { a = max(a, b); }
const ll mod = 1e9+7;

int main() {
    // your code goes here
    string s;
    cin >> s;
    cout << s[0] << s[1] << s[2] << endl;
    return 0;
}
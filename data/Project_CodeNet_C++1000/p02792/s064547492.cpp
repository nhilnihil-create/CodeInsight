#include <bits/stdc++.h>
#define repp(i,l,r)for(long long i=(l);i<(r);i++)
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define per(i,n) for (long long i = (n); i >= 0; --i)
#define all(v) v.begin(), v.end()
const int INF = 1 << 30;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

P f(int n){
    string s = to_string(n);
    return P(s.front() - '0',s.back() - '0');
}

//ミョ(-ω- ?)
int main() {
    int n;
    cin >> n;
    map<P,int> mp;
    for(int i = 1;i <= n;i++){
        P p = f(i);
        mp[p]++;
    }
    ll res = 0;
    for(int i = 1;i <= n;i++){
        P q = make_pair(f(i).second , f(i).first);
        res += mp[q];
    }
    cout << res << "\n";
    return 0;
}
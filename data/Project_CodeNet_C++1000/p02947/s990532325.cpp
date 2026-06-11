#include<bits/stdc++.h>
/* #define int long long */
/* #define double long double */
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;
typedef pair<int, int> P;
#define rrep(i,a,b) for(int i=a;i>=b;i--)

signed main(){
    int n;
    cin >> n;
    map<string, ll> m;
    string s;
    rep(i, n){
        cin >> s;
        sort(s.begin(), s.end());
        m[s]++;
    }

    ll v = 0;
    for(auto itr = m.begin(); itr != m.end(); itr++){
        ll t = itr -> second;
        v += t * (t - 1) / 2;
    }

    cout << v << endl;
}
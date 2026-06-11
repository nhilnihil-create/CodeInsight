#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(long long i=0;i<(long long)(n);i++)
#define rep2(i, s, n) for(long long i=(s);i<(long long)(n);i++)
#define all(v) v.begin(), v.end()

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using P = pair<ll, ll>;

const ll INF = (1LL<<60);

int main(){

    string s, t; cin >> s >> t;

    ll ans = 0;
    if(s[0] == t[0]) ans++;
    if(s[1] == t[1]) ans++;
    if(s[2] == t[2]) ans++;

    cout << ans << endl;

    return 0;
}
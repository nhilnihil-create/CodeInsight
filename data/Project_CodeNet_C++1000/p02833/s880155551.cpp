#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using vi = vector<int64_t>;
using vvi = vector<vi>;
using ll = long long ;
using P = pair<ll,ll>;
ll INF = 1000000007;
// ll INF = 9223372036854775807;
// ll INF = 998244353;

int main() {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    ll n;
    cin >> n;
    ll count = n/10;
    ll res = 0;
    if(n%2==1){
        cout << 0 << endl;
        return 0;
    }
    ll tmp = 10;
    res += n/10;
    n/=10;
    while(n!=0){
        res += n/5;
        n/=5;
    }
    cout << res << endl;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

map<ll, ll> mp;
ll a[200010];

int main(){
    int n;
    cin >> n;
    rep(i, n) {
        ll b;
        cin >> b;
        a[i] = b;
        mp[b]++;
    }
    ll res = 0;
    for(auto v : mp){
        ll num = v.second;
        res += num * (num-1) / 2;
    }

    rep(i, n){
        ll num = mp[a[i]];
        ll tmp = res;
        tmp -= num * (num-1) / 2;
        tmp += (num-1) * (num-2) / 2;
        cout << tmp << endl;
    }


    return 0;
}

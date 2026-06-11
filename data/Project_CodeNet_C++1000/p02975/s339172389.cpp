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


ll a[100010];

int main(){
    int n;
    cin >> n;
    rep(i, n) cin >> a[i];

    bool f = 1;

    map<ll, int> mp;
    rep(i, n) mp[a[i]]++;
    if (n%3 != 0) f = 0;
    else{
        if (mp.size() != 3) f = 0;
        else {
            vector<ll> tmp;
            for(auto v : mp){
                if (v.second != n/3) f = 0;
                tmp.push_back(v.first);
            }
            ll x = tmp[0] ^ tmp[1] ^ tmp[2];
            if (x != 0) f = 0;
        }
    }

    if (mp[0] > 0){
        if (mp[0] == n) f = 1;
        else if (n%3 == 0 && mp.size() == 2 && mp[0] == n/3) f = 1;
    }

    if (f) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}

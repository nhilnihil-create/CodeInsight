#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const ll mod = 998244353;

ll safePow(ll x, ll y){
    ll result = 1;
    rep(i, y){
        result = (result * x) % mod;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> d(n);
    rep(i, n) cin >> d[i];
    if(d[0] != 0){
        cout << 0 << endl;
        return 0;
    }
    sort(d.begin(), d.end());
    if(d[1] != 1){
        cout << 0 << endl;
        return 0;
    }

    ll cnt = 0, cur_d = 0, prev_cnt = 1;
    ll ans = 1;
    rep(i, n){
        if(d[i] == cur_d){
            cnt++;
        } else {
            if(d[i] != cur_d + 1){
                ans = 0;
                break;
            }
            ans = (ans * safePow(prev_cnt, cnt)) % mod;
            prev_cnt = cnt;
            cnt = 1;
            cur_d++;
        }
        if(i == n - 1){
            ans = (ans * safePow(prev_cnt, cnt)) % mod;
        }
    }
    cout << ans << endl;

    
    return 0;
}

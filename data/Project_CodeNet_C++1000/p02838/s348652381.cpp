#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>

const ll mod = 1000000007;

int main() {
	ll n;
	cin >> n;
	vector<ll>a(n);
    rep(i, n)cin >> a[i];
	ll ans(0);
    rep(i, 60){
        ll  cnt(0);
        rep(j, n) {
            if (a[j] >> i & 1) {
                cnt++;
            }
        }
        ll t=pow(2,i);
        t %= mod;
        ans += (((n - cnt) *cnt) % mod)*t;
        ans %= mod;
    }
    
    cout << ans;

}
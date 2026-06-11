#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=(1LL<<60);
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    if(p == 2LL || p == 5LL){
    	ll num = 0, ans = 0, m;
    	for(int i=n-1;i>=0;i--){
    		m = (s[i] - '0');
    		if(m % p == 0LL){
    			num++;
    		}
    		ans += num;
    	}
    	cout << ans << endl;
    }else{
    	vector<ll> dp(p, 0);
    	dp[0]++;
    	ll num = 0;
    	ll ans = 0, m, t = 1;
    	for(int i=n-1;i>=0;i--){
    		m = (s[i] - '0') * t;
    		m %= p;
    		num += m;
    		num %= p;
    		ans += dp[num];
    		dp[num]++;
    		t *= 10LL;
    		t %= p;
    	}
    	cout << ans << endl;
    }
    return 0;
}

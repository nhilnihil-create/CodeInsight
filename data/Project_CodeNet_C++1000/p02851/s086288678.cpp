#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll>m;
const int N = 2e5;
ll sum[N+100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,k;
	ll ans = 0;
	cin >> n >> k;
	m[0] = 1;
	for(ll i=1;i<=n;i++){
		ll a;
		cin >> a;
		sum[i] = (sum[i-1]+a)%k;
		ans += (m[(sum[i]-(i)%k+k)%k]);
		m[(sum[i]-(i)%k+k)%k]++;
		if(i-k+1>=0){
			m[(sum[i-k+1]-(i-k+1)%k+k)%k]--;
		}
	}
	if(k==1){
		cout << "0\n";
	}
	else cout << ans << "\n";
}

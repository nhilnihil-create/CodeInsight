#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define fi first
#define sc second
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector <ll> div_n;
vector <ll> div_n_1;

int main()
{
	ll n; scanf("%lld", &n);
	ll ans = 0;
	
	if(n == 2){
		printf("1\n");
		return 0;
	}
	for(ll i = 2; i * i <= n; i++){
		if(n % i == 0){
			div_n.pb(i);
			if(i * i != n) div_n.pb(n / i);
		}
		if((n - 1) % i == 0){
			div_n_1.pb(i);
			if(i * i != n - 1) div_n_1.pb((n - 1) / i);
		}
	}
	for(int i = 0; i < div_n.size(); i++){
		ll temp = n;
		while(temp % div_n[i] == 0) temp /= div_n[i];
		if(temp % div_n[i] == 1) ans++;
	}
	ans += 2 + div_n_1.size();
	
	printf("%lld\n", ans);
}
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

const ll MAXN = 3 * 1e5 + 5;
ll n, ans;
ll pre[65][MAXN];	// bit 1

int main()
{
	scanf("%lld", &n);
	
	for(ll i = 1; i <= n; i++){
		ll inp; scanf("%lld", &inp);
		
		for(ll j = 0; j < 60; j++){
			pre[j][i] = pre[j][i - 1];
			if((1LL << j) & inp) pre[j][i]++;
		}
		if(i > 1){
			for(ll j = 0; j < 60; j++){		
				if((1LL << j) & inp){
					ans = (ans + ( ((1LL << j) % mod) * (i - 1 - pre[j][i - 1]) ) % mod) % mod;
				}
				else {
					ans = (ans + ( ((1LL << j) % mod) * pre[j][i - 1] ) % mod) % mod;
				}
			}
		}
	}
	printf("%lld\n", ans);
}
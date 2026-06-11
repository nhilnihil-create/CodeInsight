#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
 
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
#define int ll
#define pb push_back
#define pii pair<int,int>
#define ff first
#define ss second

typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int MAX = 1e5+10, MOD = 1e9+7;
int isp[MAX],phi[MAX];
vector<int> prime;

int n,k;

int exp(int a, int b){
	int res = 1;
	while(b){
		if (b&1) res = (res*a)%MOD;
		b>>=1;
		a = (a*a)%MOD;
	}
	return res;
}

void linear_sieve(){
	fill(isp,isp+MAX,1);
	isp[1] = 0;
	phi[1] = 1;
	for(int i=2;i<MAX;i++){
		if (isp[i]){
			prime.emplace_back(i);
			phi[i] = -1;
		}
		for(int j=0;j<prime.size() && i*prime[j]<MAX; j++){
			isp[i*prime[j]] = 0;
			if (i%prime[j]!= 0) phi[i*prime[j]] = phi[i] * phi[prime[j]];
			else{
				phi[i*prime[j]] = 0;
				break;
			}
		}
	}
}
signed main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);




	cin>>n>>k;
	linear_sieve();
	int ans = 0;

	for(int i=1;i<=k;i++){
		for(int j = 1; j<= k/i;j++){
			ans = (ans + i*phi[j]*exp(k/(i*j),n) + MOD)%MOD;

		}
	}
	cout<<ans;
	return 0;
}
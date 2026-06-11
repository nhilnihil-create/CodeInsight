#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 1000005

ll N,K;
vector<int> G[100005];
ll num_child[SIZE];
ll fact[SIZE],inv_fact[SIZE];

ll mod_pow(ll x,ll count, ll mod){

	if(count == 0)return 1;
	ll ret = mod_pow((x*x)%mod,count/2,mod);
	if(count%2 == 1){

		ret = (ret*x)%mod;
	}
	return ret;
}


ll extgcd(ll a,ll b,ll &x,ll &y){
	ll d = a;
	if(b != 0){
		d = extgcd(b,a%b,y,x);
		y -= (a/b)*x;
	}else{
		x = 1;
		y = 0;
	}
	return d;
}

ll mod_inverse(ll a,ll m){
    ll x,y;
    extgcd(a,m,x,y);
    return (m+x%m)%m;
}

ll nCk(ll n,ll k){

	ll ret = fact[n]*inv_fact[k];
	ret %= MOD;
	ret *= inv_fact[n-k];

	return ret%MOD;
}

ll ans = 1;

void dfs(int node_id,int pre,int D){

	num_child[node_id] = 0;

	for(int i = 0; i < G[node_id].size(); i++){

		int child = G[node_id][i];
		if(child == pre)continue;

		num_child[node_id]++;
	}

	//printf("node_id:%d D:%d num_child:%lld\n",node_id,D,num_child[node_id]);

	if(D == 0){

		ans *= K;
		if(K-1 < num_child[node_id]){
			ans = 0;
			return;
		}

		ll mult = (nCk(K-1,num_child[node_id])*fact[num_child[node_id]])%MOD;
		ans *= mult;
		ans %= MOD;

		//printf("ans:%lld\n",ans);

	}else{

		if(K-2 < num_child[node_id]){
			ans = 0;
			return;
		}

		ll mult = (nCk(K-2,num_child[node_id])*fact[num_child[node_id]])%MOD;
		ans *= mult;
		ans %= MOD;
	}

	for(int i = 0; i < G[node_id].size(); i++){

		int child = G[node_id][i];
		if(child == pre)continue;

		dfs(child,node_id,D+1);
	}
}



int main(){

	fact[0] = 1;
	for(ll i = 1; i < SIZE; i++){
		fact[i] = i*fact[i-1];
		fact[i] %= MOD;
	}
	inv_fact[SIZE-1] = mod_inverse(fact[SIZE-1],MOD);
	for(ll i = SIZE-1; i >= 1; i--){

		inv_fact[i-1] = inv_fact[i]*i;
		inv_fact[i-1] %= MOD;
	}

	scanf("%lld %lld",&N,&K);

	int from,to;

	for(ll i = 0; i < N-1; i++){

		scanf("%d %d",&from,&to);
		from--;
		to--;

		G[from].push_back(to);
		G[to].push_back(from);
	}

	dfs(0,-1,0);

	printf("%lld\n",ans);

	return 0;
}

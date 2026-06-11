#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef complex <double> cp;
#define debug(a) cout<<#a<<":"<<a<<endl;
#define fr freopen("in.txt","r",stdin);
#define Fill(x,a) memset(x,a,sizeof(x))
#define cpy(a,b) memcpy(a,b,sizeof(a))
const double PI = acos(-1);
const ll INF=0x3f3f3f3f;
const ll N=1e6+7;
const ll mod=1e9+7;
ll maxn,minn;
ll T,n,m,q;
ll flag = 0;
ll g[N];
map<ll,ll>mp;
ll arr[N];

bool isprime[N];
ll prime[N/10];
void primes(){
    memset(isprime,false,sizeof(isprime));
    isprime[1]=true,m=1;
    for(ll i=2;i<N;i++){
        if(!isprime[i]){
            prime[m++] = i;
            for(ll j=i*i;j<N;j+=i)	isprime[j] = true;
        }
    }
}

void solve(ll n){ //n的因子个数
	for(ll i=1;i<=m&&prime[i]*prime[i]<=n;i++){
		if(n%prime[i]==0){
			if(mp[prime[i]]){
				flag = 1;
			}
			mp[prime[i]] = 1;
			while(n%prime[i] == 0){
				n /= prime[i];
			}
		}
	}
	if(n != 1){
		if(mp[n]){
			flag = 1;
		}
		else{
			mp[n] = 1;
		}
	} 
	return ;
}


int main(){
	primes();
	cin >> n;
	for(ll i = 1; i <= n; i ++ ){
		scanf("%lld", arr + i);
	}
	for(ll i = 1;i <= n; i++ ){
		solve(arr[i]);
		if(flag == 1){
			break;
		}
	}
	if(flag == 0){
		puts("pairwise coprime");
	}
	else{
		g[n] = arr[n];
		for(ll i = n - 1; i >= 1; i -- ){
			g[i] = __gcd(g[i + 1], arr[i]);
		}
		if(g[1] == 1){
			puts("setwise coprime");
		}
		else{
			puts("not coprime");
		}
	}
	
	
	
	
	
	
	
	
	


	return 0;
}


#include<bits/stdc++.h>
#include<cassert>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds; 
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
#define pfi(a) printf("%d",a);
#define pfl(a) printf("%lld",a);
#define pfin(a) printf("%d\n",a);
#define pfln(a) printf("%lld\n",a);
#define sfi(a) scanf("%d",&a);
#define sfl(a) scanf("%lld",&a);
#define pb push_back
#define f(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define inf INT_MAX
#define llinf LONG_LONG_MAX
const int N=1e5+5;
const int M=1e9+7;

ll tot[N];

ll modexp(ll a,ll b){
	if(b==0){
		return 1;
	}
	else if(b%2==0){
		return modexp((a*a)%M,b/2);
	}
	else{
		ll val=modexp((a*a)%M,b/2);
		return (a*val)%M;
	}
}

void solve(){
	ll n,k;
	sfl(n) sfl(k)

	ll cnt=0;

	ll ans=0;

	for(ll i=k;i>=2;i--){
		tot[i]=modexp(k/i,n);
		for(int j=i*2;j<=k;j+=i){
			tot[i]=(tot[i]-tot[j]+M)%M;
		}	
		cnt=(cnt+tot[i])%M;

		ans=(ans+(tot[i]*i)%M)%M;
	}

	cnt=(modexp(k,n)-cnt+M)%M;

	ans=(ans+cnt)%M;

	pfln(ans)


}

int main(){	
	
	solve();
	return 0;	
}
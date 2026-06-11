#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
const double eps = 1e-8;
const int NINF = 0xc0c0c0c0;
const int INF  = 0x3f3f3f3f;
const ll  mod  = 1e9 + 7;
const ll  maxn = 1e6 + 5;
const int N = 1e5 + 5;

long long n,k,f[N];

ll power(ll a,ll b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	ll ans=0;
	for(int i=k;i>=1;i--){
		f[i]=power(k/i,n);
		for(int j=2*i;j<=k;j+=i) f[i]-=f[j];
		ans=(ans+i*f[i]%mod)%mod;//大小×个数才是该数所有的和
	}
	cout<<(ans+mod)%mod<<'\n';
	return 0;
}
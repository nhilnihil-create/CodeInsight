#include <bits/stdc++.h>
#define int long long
#define maxn 100005
#define inf 2000000000000000000
#define mod 1000000007
#define pb push_back
#define mp make_pair
const double PI = acos(-1);
using namespace std;

int n,k, f[maxn],sum[maxn];
int fastmul(int x,int so){
	if (so==0) return 1; if (so==1) return x%mod;
	int t=fastmul(x,so/2); t=(t*t)%mod;
	if (so%2==1) t=(t*x)%mod;
	return t;
}
main(){
	ios::sync_with_stdio(false); cin.tie(0); srand(time(NULL));
	//freopen("inp.txt","r",stdin); //freopen("out.txt","w",stdout);
	//freopen(".inp","r",stdin); freopen(".out","w",stdout);
	cin>>n>>k; int i,j,x;
	f[1]=1; sum[1]=0;
	for (i=2;i<=k;i++){
		f[i]=fastmul(i,n); sum[i]=sum[i-1];
		int val=1;
		for (j=2;j<=sqrt(i);j++){
			if (i%j==0){
				x=i/j;
				sum[i]=sum[i]-f[x-1]+f[x]; sum[i]%=mod;
				if (i/j!=j){
					sum[i]=sum[i]-f[j-1]+f[j]; sum[i]%=mod;
				}
			}
		}
		sum[i]+=f[1]; sum[i]%=mod;
		f[i]=(f[i]+mod-sum[i])%mod;
	}
	int ans=0;
	for (i=1;i<=k;i++){
		j=(k/i);
		ans+=i*f[j]; ans%=mod;
	}
	cout<<ans;
}
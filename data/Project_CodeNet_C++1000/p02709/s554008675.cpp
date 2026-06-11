#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
const double eps = 1e-8;
const int NINF = 0xc0c0c0c0;
const int INF  = 0x3f3f3f3f;
const ll  mod  = 1e9 + 7;
const ll  maxn = 1e6 + 5;
const int N = 2000 + 5;

int n;
pair<ll,int> a[N];
ll f[N][N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(a,a+n,greater<pair<int,int> >());
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			int k=i-j;
			f[j+1][k]=max(f[j+1][k],f[j][k]+a[i].first*abs(a[i].second-j));
			f[j][k+1]=max(f[j][k+1],f[j][k]+a[i].first*abs(n-k-1-a[i].second));
		}
	}
	ll ans=0;
	for(int i=0;i<=n;i++) ans=max(ans,f[i][n-i]);
	cout<<ans;
	return 0;
}
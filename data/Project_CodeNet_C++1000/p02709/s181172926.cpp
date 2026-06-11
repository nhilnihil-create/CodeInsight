//by szh
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define SZ(x) (int((x).size()))
#define se second
#define ll long long
#define pq priority_queue
#define MP make_pair
#define pii pair<int,int>
#define mod 998244353
#define inf 0x3f3f3f3f
#define debug(x) cerr<<#x<<"="<<x<<'\n'

const int maxn=2e3+10;

int n;
pii a[maxn];
ll f[maxn][maxn];

int main(){
    std::ios::sync_with_stdio(false);
    cin>>n;
    for (int i=1;i<=n;i++) {
    	int x;
    	cin>>x;
    	a[i]=MP(x,i);
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	ll ans=0;
	f[0][0]=0;
	for (int k=0;k<=n;k++)
		for (int i=0;i<=k;i++) {
			int j=k-i;
			if (k==n) {
				ans=max(ans,f[i][j]);
				continue;
			}
			f[i+1][j]=max(f[i+1][j],f[i][j]+(ll)a[i+1+j].fi*(ll)(a[i+1+j].se-(1+i)));
			f[i][j+1]=max(f[i][j+1],f[i][j]+(ll)a[i+j+1].fi*(ll)(n-j-a[i+j+1].se));
		}
	cout<<ans;
	return 0;
}

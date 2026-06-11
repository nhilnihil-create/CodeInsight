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
#define rep(i, a, b) for (int i=a; i<(b); i++)

const int maxn=3e3+10;

int n,m;
int a[maxn];
int f[maxn][maxn];

int main(){
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    f[0][0]=1;
    rep(i,1,n+1) {
		cin>>a[i];
		rep(j,0,m+1) {
			f[i][j]=f[i-1][j]*2%mod;
			if (j-a[i]>=0) (f[i][j]+=f[i-1][j-a[i]])%=mod;
		}
	}
	cout<<f[n][m];
	return 0;
}

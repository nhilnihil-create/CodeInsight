#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define inf (int)(3e18)
#define P pair<int,int>
#define mod (int)(1e9+7)

template<class T> inline void chmin(T &a, T b) {
	a = min(a, b);
}
template<class T> inline void chmax(T &a, T b) {
	a = max(a, b);
}

int gcd(int x, int y) {
	if (y == 0)
		return x;
	return gcd(y, x % y);
}
int lcm(int x, int y) {
	return x / gcd(x, y) * y;
}

int k,q;
int d[5005];
signed main() {
	cin>>k>>q;
	rep(i,k)cin>>d[i];
	while(q--){
		int n,x,m;cin>>n>>x>>m;
		int sum=x%m;
		rep(i,k){
			int a=d[i]%m;
			if(a==0)a=m;
			sum+=a*((n-1)/k);
			if(i<(n-1)%k)sum+=a;
		}
		cout<<n-1-sum/m<<endl;
	}
}


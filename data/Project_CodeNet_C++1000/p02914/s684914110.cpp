#pragma GCC optimize("O4")
#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define MOD (ll)(1e9+7)
#define INF 1e17
#define int ll
#define EPS (1e-6)
using namespace std;
using ll=long long;
using pii=pair<int,int>;

int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }
int lcm(int a,int b) { return a/gcd(a,b)*b; }

int fpow(int b,int p)
{
	if(p==0) return 1;
	int h=fpow(b,p/2);
	if(p%2) return h*b%MOD*h%MOD;
	return h*h%MOD;
}

int dp[5010][5010];



int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n; cin>>n;
	int all=0;
	vector<int> v(n);
	for(auto &i:v){
		cin>>i;
		all^=i;
	}
	all=(~all);
	for(auto &i:v){
		i=i&all;
	}
	int now=0;
	for(int i=60;i>=0;i--){
		For(j,now,n-1){
			if(v[j]&(1ll<<i) && v[j]>v[now])
				swap(v[j],v[now]);
		}
		if(!(v[now]&(1ll<<i))) continue;
		For(j,0,n-1){
			if(j!=now && v[j]&(1ll<<i))
				v[j]^=v[now];
		}
		now++;
	}
	int mx=0;
	for(auto &i:v) mx^=i;
	cout<<(mx*2+(~all))<<"\n";
	return 0;
}




























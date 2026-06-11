#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define all(c) c.begin(), c.end()
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define gadd(x,y) x=add(x,y)
#define gmul(x,y) x=mul(x,y)
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef vector<int> vi;


const int MOD = 998244353;

inline int add(int x, int y){
	int res = x + y;	
	while(res >= MOD)res-=MOD;
	return res;
}

inline int mul(int x,int y){
	return (1LL * x * y) % MOD;
}

int modpow(int x,int p){
	int res = 1;
	while(p){
		if(p&1)gmul(res,x);
		gmul(x,x);
		p/=2;
	}
	return res;
}

inline int invert(int x){
	return modpow(x,MOD - 2);
}

const int N = 3000 + 5;

int dp[N];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n,s;
	cin >> n >> s;
	dp[0] = modpow(2,n);
	int inv = invert(2);
	rep(i,0,n){
		int x;
		cin >> x; 
		for(int i = N-1-x; i >= 0; --i){
			gadd(dp[i+x],mul(dp[i],inv));
		}
	}
	cout << dp[s] << '\n';
}

#include<bits/stdc++.h>
#define rep(i, n) for(int i=0;i<(n);++i)
#define per(i, n) for(int i=(n)-1;i>=0;--i)
#define repa(i, n) for(int i=1;i<(n);++i)
#define foreach(i, n) for(auto &i:(n))
#define pii pair<int, int>
#define pll pair<long long, long long>
#define all(x) (x).begin(), (x).end()
#define bit(x) (1ll << (x))
using namespace std;
using ll = long long;
const ll MOD = (ll)1e9+7;
//const ll MOD = 998244353;
//const ll MOD = 924844033;
const int INF = (ll)1e9+7;
const ll INFLL = (ll)1e18;
using namespace std;
template<class t>
using vvector = vector<vector<t>>;
template<class t>
using vvvector = vector<vector<vector<t>>>;
template<class t>
using priority_queuer = priority_queue<t, vector<t>, greater<t>>;
template<class t, class u> bool chmax(t &a, u b){if(a<b){a=b;return true;}return false;}
template<class t, class u> bool chmin(t &a, u b){if(a>b){a=b;return true;}return false;}

#ifdef DEBUG
#define OUTPUT(x) (output(x), outendl())
#else
#define OUTPUT(x) (void)0
#endif

ll modpow(ll x, ll b){
	ll res = 1;
	while(b){
		if(b&1)res = res * x % MOD;
		x = x * x % MOD;
		b>>=1;
	}
	return res;
}

ll modinv(ll x){
	return modpow(x, MOD-2);
}

bool was_output = false;
template<class t>
void output(t a){
	if(was_output)cout << " ";
	cout << a;
	was_output = true;
}
void outendl(){
	was_output = false;
	cout << endl;
}

//below here
int n;
int k;
vector<int> line(n);

vvvector<ll> dp;

ll func(int place,int select,int remain){
	if(place==n+1){
		return line[select];
	}

	if(dp[place][select][remain]>=0){
		return dp[place][select][remain];
	}

	ll res = INFLL;
	if(remain){
		chmin(res,func(place+1,select,remain-1));
		chmin(res,line[select]+func(place+1,0,remain-1));
	}
	if(line[select]>line[place]){
		chmin(res,line[select]-line[place]+func(place+1,place,remain));
	}else{
		chmin(res,func(place+1,place,remain));
	}
	return dp[place][select][remain] = res;
}

int main(){
	cin >> n >> k;
	line.push_back(0);
	rep(i,n){
		int d;
		cin >> d;
		line.push_back(d);
	}
	dp.resize(n+1,vvector<ll>(n+1,vector<ll>(k+1,-1)));
	cout << func(1,0,k) << endl;
	return 0;
}

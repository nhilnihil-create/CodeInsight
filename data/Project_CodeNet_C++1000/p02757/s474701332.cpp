#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define forn(i,a,b) for(int i =a;i<b;i++)
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(false);
using namespace std;

//for debugging 
/*
g++ -D_GLIBCXX_ASSERTIONS -DDEBUG -ggdb3 -std=c++14 
*/
int recur_depth = 0;
#ifdef DEBUG
#define dbg(x) {++recur_depth; auto x_=x; --recur_depth; cerr<<string(recur_depth, '\t')<<"\e[91m"<<__func__<<":"<<__LINE__<<"\t"<<#x<<" = "<<x_<<"\e[39m"<<endl;}
#else
#define dbg(x)
#endif
template<typename Ostream, typename Cont>
typename enable_if<is_same<Ostream,ostream>::value, Ostream&>::type operator<<(Ostream& os,  const Cont& v){
	os<<"[";
	for(auto& x:v){os<<x<<", ";}
	return os<<"]";
}
template<typename Ostream, typename ...Ts>
Ostream& operator<<(Ostream& os,  const pair<Ts...>& p){
	return os<<"{"<<p.first<<", "<<p.second<<"}";
}
// debugging ends here

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;

// string s;
// int n;
const int mxn = 1e5+99;
ll dp[mxn][13];
const int modi = 1e9+7;

ll binpow(int a,int b,int p){
	ll res = 1;
	while(b>0){
		if(b&1)
			res = res*a%p;
		a = a*a%p;
		b>>=1;
	}
	return res;
}

void solve(){
	int n,p;
	cin >> n >> p;
	string s;
	cin >> s;
	int suff[n+1];
	suff[n] = 0;
	for(int i =n-1;~i;i--){
		suff[i] = (suff[i+1] + (s[i]-'0')*binpow(10,n-i-1,p))%p;
		// cout << suff[i] << endl;
	}
	ll ans = 0;
	if(p==2 || p==5){
		for(int i =0;i<n;i++){
			if((s[i]-'0')%p==0){
				ans+=(i+1)*1ll;
			}
		}
	}
	else{
		map<int,ll> cnt;
		cnt[0]++;
		for(int i =n-1;~i;i--){
			ans+=cnt[suff[i]];
			cnt[suff[i]]++;
			// cout << ans << endl;/
		}
	}
	cout << ans << endl;
}

int main(){
	fast;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	// int t;cin >> t;while(t--)
		solve();
}

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

string s;
int n;
const int mxn = 1e5+99;
ll dp[mxn][13];
const int modi = 1e9+7;

ll find(int idx, int rem){
	// cout << idx << " " << rem << endl;
	if(idx>=n){
		if(rem == 5)
			return 1ll;

		return 0ll;
	}

	ll &ans = dp[idx][rem];
	if(ans!=-1){
		return ans;
	}
	ans = 0;
	if(s[idx]=='?'){
		for(int i =0;i<=9;i++){
			ans = ans + find(idx+1,(rem*10+i)%13);
			ans%=modi;
		}
	}
	else{
		ans+=find(idx+1,(rem*10+(s[idx]-'0'))%13);
		ans%=modi;
	}
	return ans;

}


void solve(){
	cin >> s;
	n = s.length();
	memset(dp,-1,sizeof(dp));
	cout << find(0,0) << endl;
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

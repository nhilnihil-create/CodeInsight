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

void solve(){
	int n,m;
	cin >> n >> m;
	vi idxs[m+1];
	int vals[n];
	for(int i =0;i<n;i++){
		int a,b;
		cin >> a >> b;
		if(a<=m){
			idxs[a].pb(i);
		}
		vals[i] = b;
	}
	multiset<int> mset;
	int ans = 0;
	// dbg(idxs);
	for(int i =1;i<=m;i++){
		for(auto e:idxs[i]){
			mset.insert(-vals[e]);
			// cout << i << " " << e << endl;
		}

		if(!mset.empty()){
			ans+= -*mset.begin();
			mset.erase(mset.begin());
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

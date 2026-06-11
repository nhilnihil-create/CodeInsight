#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b
//priority_queue<ll, vector<ll>, greater<ll>> q;
ll dp[55][55][5000];

signed main(){
	//cout << fixed << setprecision(10);
	ll n,k; cin>>n>>k;
	vl a(n);
	rep(i,0,n)cin>>a[i],a[i]--;
	vl s;
	vl t(n+1,-1);
	ll v=0;
	while(t[v]==-1){
		t[v]=s.size();
		s.push_back(v);
		v=a[v];
	}
	ll c = s.size()-t[v];
	ll l = t[v];
	if(k<l)cout << s[k]+1<< endl;
	else{
		k-=l;
		k%=c;
		cout << s[k+l]+1<<endl;
	}



	return 0;
}
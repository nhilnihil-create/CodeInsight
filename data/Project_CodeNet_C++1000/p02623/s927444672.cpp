#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i = 0;i<((ll)(n));i++)
#define reg(i,a,b) for(ll i = ((ll)(a));i<=((ll)(b));i++)
#define irep(i,n) for(ll i = ((ll)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(ll i = ((ll)(b));i>=((ll)(a));i--)
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T = int> void print(vector<T> v){for(auto a:v)cout<<a<<" ";cout<<endl;}

/*
片方を決め打って２分探索

*/

ll n,m,k,a[200010],sum=0,cur=0,ans=0;
vector<ll> b;

int main(void){
	cin>>n>>m>>k;
	rep(i,n)cin>>a[i];
	b.push_back(0);
	rep(i,m){
		ll x;
		cin>>x;
		sum+=x;
		b.push_back(sum);
	}
	rep(i,n+1){
		if(cur>k)break;
		ll pos =  upper_bound(b.begin(), b.end(), k-cur) - b.begin();
		ans = max(ans, i + pos - 1);
		cur += a[i];
	}
	cout<<ans<<endl;
	return 0;
}
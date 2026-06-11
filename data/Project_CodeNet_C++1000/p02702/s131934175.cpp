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
*/

ll dp[200010]={},ans=0,c=1;
map<ll,ll> m;
string s;

int main(void){
	cin>>s;
	m[0]=1;
	irep(i,s.size()){
		dp[i] = (dp[i+1] + c*(s[i]-'0')) % 2019;
		c = (c*10) % 2019;
		m[dp[i]]++;
	}
	for(auto itr=m.begin(); itr!=m.end(); itr++){
		ans += (itr->second)*(itr->second-1)/2;
	}
	cout<<ans<<endl;
	return 0;
}
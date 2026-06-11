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

ll x,n,p[110],a[110]={},l=1e9,ans=0;

int main(void){
	cin>>x>>n;
	rep(i,n)cin>>p[i];
	rep(i,n)a[p[i]]=1;
	reg(i,0,101)if(abs(x-i)<l && a[i]==0){
		ans=i;
		l=abs(x-i);
	}
	cout<<ans<<endl;
	return 0;
}
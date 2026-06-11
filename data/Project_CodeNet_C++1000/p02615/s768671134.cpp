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
大きい順に置くのが最適
*/

ll n,a[200010],ans=0;

int main(void){
	cin>>n;
	rep(i,n)cin>>a[i];
	sort(a,a+n,std::greater<>());
	ans=a[0];
	reg(i,1,n/2-1)ans+=a[i]*2;
	if(n%2==1)ans+=a[n/2];
	cout<<ans<<endl;
	return 0;
}
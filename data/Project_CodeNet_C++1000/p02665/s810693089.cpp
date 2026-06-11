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

bool ok=true;
ll n,a[100010],sum=0,c=1,ans=1;

int main(void){
	cin>>n;
	rep(i,n+1)cin>>a[i];
	rep(i,n+1)sum+=a[i];
	if(a[0]>1)ok=false;
	if(a[0]==1 && n!=0)ok=false;
	reg(i,1,n){
		sum-=a[i];
		ll yoyuu = min(c*2 - a[i], sum);  // 何個下に伸ばせるか
		if(yoyuu<0)ok = false;
		c = yoyuu;
		ans += c+a[i];
	}
	cout<<(ok ? ans : -1)<<endl;
	return 0;
}
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
どの数の倍数でもないものを探す。
ソートして、小さいやつから見て、その数の倍数を順次消していく。
*/

ll n,a[200010],b[1000010]={},ans=0;
ll dp[1000010]={};

int main(void){
	cin>>n;
	rep(i,n)cin>>a[i];
	rep(i,n)b[a[i]]++;
	sort(a,a+n);
	rep(i,n){
		if(b[a[i]]==0)continue;
		if(dp[a[i]]==0){
			dp[a[i]]=1;  // 同じ要素があったときに繰り返しやらないように
			if(b[a[i]]==1)ans++;  // 同じ要素があったら絶対に性質を満たさない。
			for(ll j=2; a[i]*j<=1000000; j++){
				dp[a[i]*j]=1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
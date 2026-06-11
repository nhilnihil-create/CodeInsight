/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither long longo the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const long long inf=0x3f3f3f3f;
const double eps=1e-6;
const long long mod=1000000007;
typedef long long ll;
inline string getstr(string &s,long long l,long long r){string ret="";for(long long i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
long long modpow(long long x,long long y,long long md=mod){long long ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
inline long long Rand(){return rand()*32768+rand();}
long long n,k,s,t;
long long a[55];
long long c[55][55];
vector<long long>g1[20],g0[20];
long long num[55],ban[55];
long long calc(long long x,long long y){
	if(y>x)return 1ll<<x;
	else{
		long long ret=0;
		for(long long i=0;i<=y;i++)ret+=c[x][i];
		return ret;
	}
}
long long func(long long mask){
	map<long long,long long>mp;
	long long sum=0;
	for(long long i=1;i<=n;i++)if(!ban[i]){
		mp[a[i]&mask]++;sum++;
	}
	long long ans=0;
	for(auto p:mp){
		ans+=calc(p.second,k)-1;
	}
	ans++;
//	cerr<<"return: "<<mask<<" "<<ans<<endl;
	return ans;
}
signed main(){
	string s;cin>>s;cout<<s[0]<<s[1]<<s[2]<<endl;
  	return 0;
}
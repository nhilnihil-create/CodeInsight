/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#endif
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n;
multiset<int>S,T;
int main(){
	cin>>n;
	for(int i=0;i<(1<<n);i++){
		int x;cin>>x;S.insert(x);
	}
	T.insert(*S.rbegin());
	S.erase(S.find(*S.rbegin()));
	for(int i=1;i<=n;i++){
		vector<int>Insert;
		auto x=T.rbegin();
		for(;x!=T.rend();x++){
			auto itr=S.lower_bound(*x);
			if(itr==S.begin()){
				puts("No");
				return 0;
			}
			itr--;
			Insert.push_back(*itr);
			S.erase(itr);
		}
		for(auto x:Insert)T.insert(x);
	}
	puts("Yes");
	return 0;
}
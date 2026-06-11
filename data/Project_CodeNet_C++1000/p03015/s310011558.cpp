#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v)   (v).begin(),(v).end()
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define INF      (int)1e9
#define EPS      (double)1e-9
#define MOD      ((int)1e9+7)
using namespace std;
typedef long long     llong;
typedef vector<int>   vi;
typedef vector<vi >   vvi;
typedef vector<vvi >  vvvi;
typedef pair<int,int> pii;
template<class Type> void line(const Type &a){int cnt=0;for(const auto &elem:a){if(cnt++)cerr<<' ';cerr<<elem;}cerr<<endl;}

template<typename Type_k,typename Type_p>
Type_p mod_pow(long long n,Type_k k,Type_p p){//n^k(mod p).
	if(k==0) return 1;
	long long res=mod_pow(n*n%p,k/2,p);
	if(k&1) res=res*n%p;
	return res;
}

int main(){//解説参考.
	string s;
	cin>>s;
	
	llong ans=0;
	int len=s.size();
	int cnt=0;
	REP(i,len){
		if(s[i]=='1'){
			cnt++;
			llong tmp=(llong)mod_pow(2LL,cnt-1,MOD)*mod_pow(3LL,len-i-1,MOD)%MOD;
			ans=(ans+tmp)%MOD;
		}
	}
	ans=(ans+mod_pow(2LL,cnt,MOD))%MOD;
	
	cout<<ans<<endl;
}
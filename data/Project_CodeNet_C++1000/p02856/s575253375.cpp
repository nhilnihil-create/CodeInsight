#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
template<typename ty1,typename ty2>
inline int add(ty1 x, ty2 y) {
	if(y>=MOD)y%=MOD;
	if(x>=MOD)x%=MOD;
    x += y; return x < MOD ? x : x - MOD;
}
template<typename ty1,typename ty2>
inline void addto(ty1 &x, ty2 y) {
		  if(y>=MOD)y%=MOD;
		  if(x>=MOD)x%=MOD;
	      x += y; if (x >= MOD) x -= MOD;
}
template<typename ty1,typename ty2>
inline int sub(ty1 x, ty2 y) {
		if(y>=MOD)y%=MOD;
		 if(x>=MOD)x%=MOD;
        x -= y; return x < 0 ? x + MOD : x;
}
template<typename ty1,typename ty2>
inline void subto(ty1 &x, ty2 y) {
	if(y>=MOD)y%=MOD;
	if(x>=MOD)x%=MOD;
    x -= y; if (x < 0) x += MOD;
}
template<typename ty1,typename ty2>
inline int mul(ty1 x, ty2 y) {
        if(y>=MOD)y%=MOD;
		if(x>=MOD)x%=MOD;
        return 1ll * x * y % MOD;
}
template<typename ty1,typename ty2>
void multo(ty1 &x, ty2 y) {
        if(y>=MOD)y%=MOD;
		if(x>=MOD)x%=MOD;
        x=1ll * x * y % MOD;
}

#define MAX 200002

int n;
int m;

vector<pair<long long int,long long int> > v;
int main(){
	cin>>m;
	long long int sum=0;
	long long int cn=0;
	for(int i=0;i<m;i++){
		long long int d,c;
		scanf("%lld%lld",&d,&c);
		v.push_back(make_pair(d,c));
		sum+=(d*c);
		cn+=c;
	}
	sum-=9;
	sum+=8;
	sum/=9LL;
	sum+=cn-1;
	printf("%lld\n",sum);
	return 0;
}

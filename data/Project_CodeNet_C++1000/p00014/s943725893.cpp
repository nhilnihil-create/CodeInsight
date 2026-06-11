#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for(int i = (l);i < (r);i++)
#define ALL(x) (x).begin(),(x).end()
template<typename T> bool chmax(T& a,const T& b){return a < b ? (a = b,true) : false;}
template<typename T> bool chmin(T& a,const T& b){return b < a ? (a = b,true) : false;}
typedef long long ll;

const int N = 600;

int main()
{
	ll D;
	while(~scanf("%lld",&D)){
		ll ans = 0;
		for(int i = 0;i < N;i += D){
			ans += i * i * D;
		}
		printf("%lld\n",ans);
	}

	return 0;
}
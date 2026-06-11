#include "bits/stdc++.h"

#define REP(i,num) for(ll i=0;i<(num);++i)
#define LOOP(i) while(i--)
#define ALL(c) c.begin(),c.end()
#define PRINTALL(c) for(auto pitr=c.begin();pitr!=c.end();++pitr){cout<<*pitr;if(next(pitr,1)!=c.end())cout<<' ';}cout<<endl;
#define PAIRCOMP(c,comp) [](const pair<ll,ll>& lhs,const pair<ll,ll>& rhs){return lhs.c comp rhs.c;}

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;

constexpr ll atcoder_mod = 1e9+7;

template<typename T=ll>
T in(){T x; cin >> x; return (x);}
template<typename T=ll,typename C=vector<T>>
C vecin(int N){C x(N);REP(i,N){x[i]=in<T>();}return move(x);}

void vout(){cout << endl;}
template<typename Head,typename... Tail>
void vout(Head&& h,Tail&&... t){cout << ' ' << h;vout(forward<Tail>(t)...);}
void out(){cout << endl;}
template<typename Head,typename... Tail>
void out(Head&& h,Tail&&... t){cout << h;vout(forward<Tail>(t)...);}

template<typename T>
bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>
bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);

	auto N=in(),M=in();
	vector<pair<ll,ll>> P(M);
	REP(i,M){
		P[i].first = in();
		int B=in();
		ll X=0;
		REP(j,B){
			int c=in();
			X |= 1ll<<(c-1);
		}
		P[i].second=X;
	}
	int L=1<<N;
	vvll dp(M+1,vll(L,1ll<<60));
	dp[0][0] = 0;

	REP(i,M){
		REP(j,L){
			chmin(dp[i+1][j],dp[i][j]);
			chmin(dp[i+1][j|P[i].second],dp[i][j]+P[i].first);
		}
	}

	out(dp[M][L-1]>=1ll<<60 ? -1 : dp[M][L-1]);
	return 0;
}

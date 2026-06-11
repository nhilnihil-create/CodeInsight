#include "bits/stdc++.h"

#define REP(i,num) for(int i=0;i<(num);++i)
#define LOOP(i) while(i--)
#define ALL(c) c.begin(),c.end()
#define PRINTALL(c) for(auto pitr=c.begin();pitr!=c.end();++pitr){cout<<*pitr;if(next(pitr,1)!=c.end())cout<<' ';}cout<<endl;
#define PAIRCOMP(c,comp) [](const pair<ll,ll>& lhs,const pair<ll,ll>& rhs){return lhs.c comp rhs.c;}

using namespace std;
using ll = long long;

constexpr ll atcoder_mod = 1e9+7;

template<typename T=int>
T in(){T x; cin >> x; return (x);}
template<typename T=int,typename C=vector<T>>
C vecin(int N){C x(N);REP(i,N){x[i]=in<T>();}return move(x);}

void vout(){cout << endl;}
template<typename Head,typename... Tail>
void vout(Head&& h,Tail&&... t){cout << ' ' << h;vout(forward<Tail>(t)...);}
void out(){cout << endl;}
template<typename Head,typename... Tail>
void out(Head&& h,Tail&&... t){cout << h;vout(forward<Tail>(t)...);}

class Combination{
	constexpr static int atcoder_mod = 1000000007;
	vector<ll> fac,finv,inv;
public:
	Combination(ll N){
		fac.resize(N+1);
		finv.resize(N+1);
		inv.resize(N+1);
		fac[0] = fac[1] = 1;
		finv[0] = finv[1] = 1;
		inv[1] = 1;
		for(int i=2;i<=N;i++){
			fac[i] = fac[i-1] * i % atcoder_mod;
			inv[i] = atcoder_mod - inv[atcoder_mod%i] * (atcoder_mod/i) % atcoder_mod;
			finv[i] = finv[i-1] * inv[i] % atcoder_mod;
		}
	}
	ll Caluclation(ll n,ll r){
		if(n < r) return 0;
		if (n < 0 || r < 0) return 0;
		return fac[n] * (finv[r] * finv[n-r] % atcoder_mod) % atcoder_mod;
	}
	ll GetFInv(ll i){
		return finv[i];
	}
};

ll BallBoxCombination5(ll n,ll k){
	Combination comb(k);
	return comb.Caluclation(k,n);
}

ll BallBoxCombination6(ll n,ll k){
	Combination comb(n-1);
	return comb.Caluclation(n-1,k-1);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);

	int N=in(),K=in();
	int R=N-K;
	REP(i,K){
		ll X=BallBoxCombination5(i+1,R+1);
		ll Y=BallBoxCombination6(K,i+1);
		out((X*Y)%atcoder_mod);
	}
	return 0;
}

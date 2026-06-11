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

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);

	ll N=in(),K=in();
	auto A=vecin(N);

	vector<ll> PS(N,0),NS(N,0);
	REP(i,N){
		REP(j,N){
			if(A[i]>A[j]){
				if(i>j){
					PS[i]++;
				}
				else NS[i]++;
			}
		}
	}

	ll S=0;
	ll PST = K,NST = K;
	if(K%2){
		NST *= (K+1LL)/2LL;
		NST %= atcoder_mod;
		PST *= (K-1LL)/2LL;
		PST %= atcoder_mod;
	}
	else{
		NST /= 2LL;
		NST *= K+1LL;
		NST %= atcoder_mod;
		PST /= 2LL;
		PST *= K-1LL;
		PST %= atcoder_mod;
	}

	REP(i,N){
		S += (NS[i]*NST)%atcoder_mod;
		S %= atcoder_mod;
		S += (PS[i]*PST)%atcoder_mod;
		S %= atcoder_mod;
	}

	out(S);
	return 0;
}

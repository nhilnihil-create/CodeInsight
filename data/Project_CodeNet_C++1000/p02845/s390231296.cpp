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

ll powermod(ll a,ll b,ll m){
	if(b==0){
		return 1LL;
	}
	if(b%2){
		return (a*powermod(a,b-1LL,m))%m;
	}
	return powermod((a*a)%m,b/2LL,m);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	
	int N=in();
	auto A=vecin(N);
	if(A[0]!=0){
		out(0);
		return 0;
	}

	int P[3]={1,0,0};
	ll C=3;
	for(int i=1;i<N;i++){
		ll M=0;
		REP(j,3){
			if(P[j]==A[i]){
				M++;
			}
		}
		if(M==0){
			out(0);
			return 0;
		}
		
		REP(j,3){
			if(P[j]==A[i]){
				P[j]++;
				break;
			}
		}

		C *= M;
		C %= atcoder_mod;
	}

	out(C);
	return 0;
}

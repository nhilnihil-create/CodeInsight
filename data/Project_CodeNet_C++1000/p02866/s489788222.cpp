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
	auto D=vecin(N);
	auto Dmax = *max_element(ALL(D));

	if(D[0]!=0){
		out(0);
		return 0;
	}

	map<int,int> M;
	REP(i,N) M[D[i]]++;

	if(M[0]!=1){
		out(0);
		return 0;
	}

	ll A=1;
	REP(i,Dmax){
		A *= powermod(M[i],M[i+1],998244353);
		A %= 998244353;
	}

	out(A);
	return 0;
}

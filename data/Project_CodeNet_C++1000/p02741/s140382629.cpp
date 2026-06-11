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
T in(){ T x; cin >> x; return (x); }
template<typename T=int,typename C=vector<T>>
C vecin(int N){ C x(N);REP(i,N){ x[i]=in<T>(); }return move(x); }

void vout(){ cout << endl; }
template<typename Head,typename... Tail>
void vout(Head&& h,Tail&&... t){ cout << ' ' << h;vout(forward<Tail>(t)...); }
void out(){ cout << endl; }
template<typename Head,typename... Tail>
void out(Head&& h,Tail&&... t){ cout << h;vout(forward<Tail>(t)...); }

template<typename T>
bool chmin(T& a,T b){ if(a>b){ a=b;return true; }return false; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);

	ll A[32]={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
	ll K=in();
	
	out(A[K-1]);
	return 0;
}

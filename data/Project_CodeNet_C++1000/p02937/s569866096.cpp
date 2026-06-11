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

	string S=in<string>(),T=in<string>();
	vvll C(26);
	int N=S.size(),K=T.size();
	REP(i,N) C[S[i]-'a'].push_back(i+1);
	REP(i,K){
		if(C[T[i]-'a'].empty()){
			out(-1);
			return 0;
		}
	}
	ll A=0,P=1;
	REP(i,K){
		ll Q=T[i]-'a';
		auto res = lower_bound(ALL(C[Q]),P);
		if(res!=C[Q].end()){
			A += (*res)-P+1;
			P = *res+1;
		}
		else{
			A += N-P+1;
			A += C[Q].front();
			P = C[Q].front()+1;
		}
	}

	out(A);
	return 0;
}

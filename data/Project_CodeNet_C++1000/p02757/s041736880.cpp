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

	int N=in(),P=in();
	string S=in<string>();
	vector<int> M(N+1,0);
	reverse(ALL(S));
	if(P==2 || P==5){
		ll A=0;
		REP(i,N){
			if(((S[i]-'0')%P)==0){
				A += N-i;
			};
		}
		out(A);
	}
	else{
		REP(i,N){
			int V=M[i];
			int X=(S[i]-'0')*powermod(10,i,P);
			M[i+1] = (X+V)%P;
		}
		map<int,ll> C;
		REP(i,N+1){
			C[M[i]]++;
		}
		ll A=0;
		for(auto& x:C){
			A += x.second*(x.second-1LL)/2LL;
		}
		out(A);
	}
	return 0;
}

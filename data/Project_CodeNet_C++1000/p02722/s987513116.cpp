#include "bits/stdc++.h"

#define REP(i,num) for(ll i=0;i<(num);++i)
#define FOR(i,c,num) for(ll (i)=(c);(i)<(num);++(i))
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

vector<ll> enum_div(ll n){
	vector<ll> ret;
	for(ll i=1;i*i<=n;++i){
		if(n%i==0){
			ret.push_back(i);
			if(i*i!=n){
				ret.push_back(n/i);
			}
		}
	}
	sort(ALL(ret));
	return ret;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);

	auto N=in();
	auto D1 = enum_div(N);
	auto D2 = enum_div(N-1);
	vll C;
	set_difference(ALL(D2),ALL(D1),back_inserter(C));

	ll S=C.size();
	for(auto& x:D1){
		if(x==1) continue;
		ll X = N/x;
		while(X>=x && !(X%x)){
			X /= x;
		}
		if((X%x)==1ll) S++;
	}

	out(S);
	return 0;
}

#include "bits/stdc++.h"

#define REP(i,num) for(int i=0;i<(num);++i)
#define ALL(c) c.begin(),c.end()
#define LOOP(i) while(i--)
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

template<typename T>
bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);

	ll N=in();
	deque<ll> A(N);
	REP(i,N){
		A[i]=in();
	}
	sort(ALL(A));
	ll left = A.front();
	ll right = A.back();

	vector<pair<int,int>> H;
	for(int i=1;i<N-1;i++){
		if(A[i]<0){
			H.emplace_back(right,A[i]);
			right -= A[i];
		}
		else{
			H.emplace_back(left,A[i]);
			left -= A[i];
		}
	}
	
	out(right-left);
	for(auto& x:H) out(x.first,x.second);
	out(right,left);
	return 0;
}

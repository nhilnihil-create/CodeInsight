#include "bits/stdc++.h"

#define REP(i,num) for(int i=0;i<(num);++i)
#define ALL(c) c.begin(),c.end()
#define PRINTALL(c) for(auto& x:c){cout<<x<<' ';}cout<<endl;
#define PAIRCOMP(c,comp) [](const pair<ll,ll>& lhs,const pair<ll,ll>& rhs){return lhs.c comp rhs.c;}

constexpr int atcoder_mod = 1e9+7;

using namespace std;
using ll = long long;

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

	int N=in();
	auto comp = [](const pair<int,int>& l,const pair<int,int>& r){return l.first==r.first ? l.second<r.second : l.first<r.first;};
	vector<pair<int,int>> P(N);
	map<pair<int,int>,int,decltype(comp)> x(comp);
	REP(i,N){
		P[i].first=in();
		P[i].second=in();
	}
	REP(i,N){
		for(int j=0;j<N;j++){
			if(i==j) continue;
			x[make_pair(P[j].first-P[i].first,P[j].second-P[i].second)]++;
		}
	}
	int max_num = 0;
	for(auto& y:x){
		max_num = max(max_num,y.second);
	}
	out(N-max_num);
	
	return 0;
}

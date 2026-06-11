#include <bits/stdc++.h>
using namespace std;
#define FOR(i,o,n) for(long long i = o;i<n;i++)
#define oneforall ios::sync_with_stdio(false);cin.tie(0);
#define all(v) (v).begin(),(v).end()
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) long long __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
#define int long long 
const long long INF=1e18;
void in(){} template <typename T,class... U> void in(T &t,U &...u){ cin >> t; in(u...);}
void out(){cout << "\n";} template <typename T,class... U> void out(const T &t,const U &...u){ cout << t; if(sizeof...(u)) cout << " "; out(u...);}
typedef vector<int> vi;
typedef vector<long long> vl;
typedef long long ll;
typedef vector<pair<long, long > > vpll;
typedef vector<pair<int, int > > vpii;


int rick[256];

int32_t main() {
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	oneforall
	
	
	
	ini(n);
	vpii morty;
	FOR(i,0,n){
		ini(x);
		ini(x1);
		morty.push_back(make_pair(x,x1));
	}
	map<pair<int,int>,int>map1;
	FOR(i,0,n){
		pair<int,int> tmp;
		FOR(i1,0,n){
			if(i1 == i)continue;
			map1[make_pair(morty[i].first-morty[i1].first,morty[i].second-morty[i1].second)]++;
		}
	}
	int rick = 0;
	pair<int,int> rick1;
	for(auto x:map1){if(x.second>rick){rick = x.second;rick1 = x.first;}}
	out(n-rick);










	return 0;
}

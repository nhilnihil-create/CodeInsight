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
		morty.push_back(make_pair(x-x1,x+x1));
	}
	
	sort(all(morty),[&](pair<int,int> x,pair<int,int> x1){return x.second<x1.second;});
	int tmp = -INF;
	int rick = 0;
	FOR(i,0,n){
		if(tmp<=morty[i].first){
			rick++;
			tmp = morty[i].second;
		}
	}
	out(rick);
	
	
















	return 0;
}

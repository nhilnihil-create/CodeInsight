#include <bits/stdc++.h>
using namespace std;
#define FOR(i,o,n) for(long long i = o;i<n;i++)
#define oneforall ios::sync_with_stdio(false);cin.tie(0);
#define all(v) (v).begin(),(v).end()
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) long long __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
const long long INF=1e18;
void in(){} template <typename T,class... U> void in(T &t,U &...u){ cin >> t; in(u...);}
void out(){cout << "\n";} template <typename T,class... U> void out(const T &t,const U &...u){ cout << t; if(sizeof...(u)) cout << " "; out(u...);}
typedef vector<int> vi;
typedef vector<long long> vl;
typedef long long ll;
typedef vector<pair<long,long>> vpll;
typedef vector<pair<int,int>> vpii;
int main() {
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
	vpii a(n);
	FOR(i,0,n){in(a[i].first);a[i].second = i+1;}
	ll total = 0;
	sort(all(a));
	reverse(all(a));
	multiset<int> greater;
	greater.insert(0);
	greater.insert(0);
	greater.insert(n+1);
	greater.insert(n+1);
	for(auto x:a){
		ll num = x.first;
		int id = x.second;
		auto it = greater.lower_bound(id);
		int R1 = *it;it++;
		int R2 = *it;
		it--;it--;
		int L1 = *it;it--;
		int L2 = *it;
		total+=num*((R1-id)*(L1-L2)+(R2-R1)*(id-L1));
		greater.insert(id);
	}
	out(total);
	return 0;
}

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
#define FORR(x,arr) for(auto& x:arr)
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
	map<int,int>map1;
	int mo = 1000000007;
	int morty[3];
	FOR(i,0,3)morty[i] =0;
	int rick = 1;
	FOR(i,0,n){
		ini(x);
		int tmp = 0;
		int pos = -1;
		FOR(i,0,3){
			if(x == morty[i]){pos = i;tmp++;}
		}
		//out(tmp);
			rick*=tmp;
			rick%=mo;
			morty[pos]++;
	}
	rick+=mo;
	rick%=mo;
	out(rick);















	return 0;
}
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
#define ZERO(a) memset(a,0,sizeof(a))





//3111111111111111111111111111111

	vi morty(310000,0);

	void solve(){

		
		ini(n);
		ini(k);
		int rick = 0;
		map<int,int> map1;
		map1[0] = 1;
		vi pre;
		pre.push_back(0);
		FOR(i,1,n+1){
			ini(morty[i]);
			pre.push_back(pre[i-1]+morty[i]);
			if(i>=k)map1[(pre[i-k]-(i-k))%k]--;
			//out((pre[i]-i)%k,map1[(pre[i]-i)%k]);
			rick+=map1[(pre[i]-i)%k];
			map1[(pre[i]-i)%k]++;
		}
		out(rick);
















	}









































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

	solve();
	


	return 0;
}
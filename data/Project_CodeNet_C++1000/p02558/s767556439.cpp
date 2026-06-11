//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;
using namespace atcoder;
typedef long long ll;

#define INF INT_MAX
#define LLINF LLONG_MAX
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007
#define MODB  998244353 

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
    for (T& x: vec) { is >> x; }
    return is;
}

int main() {
	ll ans = 0;
	ll tmp;
	int n; cin >> n;
	int q;  cin >> q;
	int t, u, v;
	dsu d(n);
	REP(i, q ){
		cin >> t >> u >> v;
		if(t==0){
			d.merge(u, v);
		}
		else{
			if(d.same(u, v)) cout << 1 << endl;
			else cout << 0 << endl;
		}
	}
	//cout << ans << endl;
}
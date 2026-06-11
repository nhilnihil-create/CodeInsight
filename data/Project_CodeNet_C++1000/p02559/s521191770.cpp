//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
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
	int q; cin >> q;
	int t, p, x, l, r;
	fenwick_tree<ll> fw(n);
	REP(i, n){
		cin >> tmp;
		fw.add(i, tmp);
	}
	REP(i, q){
		cin >> t;
		if(t==0){
			cin >> p >> x;
			fw.add(p, x);
		}
		else{
			cin >> l >> r;
			cout << fw.sum(l, r) << endl;
		}
	}
	//cout << ans << endl;
}
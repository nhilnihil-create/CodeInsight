//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF INT_MAX
#define LLINF LLONG_MAX
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
    for (T& x: vec) { is >> x; }
    return is;
}

int main() {
	ll ans = 0;
	ll tmp;
	int x, n; cin >> x >> n;
	set<int> s;
	REP(i, 102) s.insert(i);
	REP(i, n ) {
		cin >> tmp;
		s.erase((int) tmp);
	}
	auto it = s.lower_bound(x);
	auto mim = s.lower_bound(x);
	mim--;
	if(abs(*it - x) >= abs(*mim - x)) cout << *mim << endl;
	else cout << *it << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
	
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	
	double l;cin >> l;

	
	
	cout << std::fixed << std::setprecision(15) << l*l*l/27 << endl;
	
	return 0;
}

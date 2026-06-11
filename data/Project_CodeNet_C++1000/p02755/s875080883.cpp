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
	
	
	int a, b; cin >> a >> b;
	
	for(int i = 1;i < 1000000; i++){
		int aa = i * 0.08;
		int bb = i * 0.10;
		if(aa == a && bb == b){
			cout << i << endl;
			return 0;
		}
	}
	
	
	cout << -1 << endl;
	
	return 0;
}

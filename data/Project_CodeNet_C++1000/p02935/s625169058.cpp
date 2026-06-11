#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<double> v(n);
	rep(i,n) cin >> v[i];
	sort(v.begin(), v.end());
	rep(i,n-1){
		v[i+1] = (v[i+1] + v[i]) / 2;
	}
	cout << fixed << setprecision(12) << v[n-1] << endl;
	return 0;
}
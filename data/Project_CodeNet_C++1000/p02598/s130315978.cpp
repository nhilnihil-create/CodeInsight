#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

//#include "atcoder/all"
//using namespace atcoder;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	int ok = 1e9, ng = 0;
	while(ok - ng > 1){
		int mid = (ok + ng) / 2;
		int cost = 0;
		rep(i,n){
			cost += max(0, (a[i] + mid - 1) / mid - 1);
		}
		if(cost <= k) ok = mid;
		else ng = mid;
	}
	cout << ok << endl;
	return 0;
}
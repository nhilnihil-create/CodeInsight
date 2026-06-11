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
	vector<int> v(n), p(n), q(n);
	rep(i,n) cin >> p[i];
	rep(i,n) cin >> q[i];
	rep(i,n) v[i] = i+1;
	int pid = 0, qid = 0;
	int cnt = 1;
	do{
		bool P = true;
		bool Q = true;
		rep(i,n){
			if(v[i] != p[i]) P = false;
			if(v[i] != q[i]) Q = false;
		}
		if(P) pid = cnt;
		if(Q) qid = cnt;
		++cnt;
	} while(next_permutation(v.begin(), v.end()));
	int ans = abs(pid - qid);
	cout << ans << endl;
	return 0;
}
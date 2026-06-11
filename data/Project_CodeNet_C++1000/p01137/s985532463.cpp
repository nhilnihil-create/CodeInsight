#include "bits/stdc++.h"

#define REP(i,n) for(int i=0;i<n;++i)
#define RREP(i,n) for(int i=n-1;i>=0;--i)
#define FOR(i,m,n) for(int i=m;i<n;++i)
#define RFOR(i,m,n) for(int i=n-1;i>=m;--i)
#define ALL(v) v.begin(),v.end()
#define PB(a) push_back(a)
#define INF 1000000001
#define MOD 1000000007

const int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
const int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

using namespace std;


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	while (1) {
		int e, ans=INF;
		cin >> e;
		if (!e) break;
		for (int i = 0;i*i*i <= e;++i) {
			int y = sqrt(e - i*i*i);
			int x = e - i*i*i - y*y;
			ans = min(ans, x + y + i);
		}
		cout << ans << endl;
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//container util
#define SORT(c) sort((c).begin(),(c).end())

//repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//print
#define pv(val) cerr << #val << '=' << (val) << endl

const int INF = 1e9;

int main(void){

	
	int A, B, M; cin >> A >> B >> M;
	vector<int> a(A);
	vector<int> b(B);

	REP(i,A) cin >> a[i];
	REP(i,B) cin >> b[i];

	vector<int> x(M);
	vector<int> y(M);
	vector<int> c(M);

	REP(i,M) cin >> x[i] >> y[i] >> c[i];

	int ans = INF;
	REP(i,M){
		int g = x[i] - 1;
		int f = y[i] - 1;
		ans = min(ans, a[g]+b[f] - c[i]);
	}

	SORT(a);
	SORT(b);

	ans = min(ans, a.front() + b.front());
	cout << ans << endl;


	return 0;

}

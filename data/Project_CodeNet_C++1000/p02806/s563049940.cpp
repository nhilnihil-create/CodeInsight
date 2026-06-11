#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//container util
#define SORT(c) sort((c).begin(),(c).end())
#define all(a) (a).begin(), (a).end()

//repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//print
#define pv(val) cerr << #val << '=' << (val) << endl

const int INF = 1e9;

int main(void){

	int N; cin >> N;
	vector<string> s(N);
	vector<int> t(N);

	REP(i,N) cin >> s[i] >> t[i];
	string X; cin >> X;

	bool ap = false;
	int ans = 0;
	REP(i,N){
		if(ap) ans += t[i];
		if(s[i] == X) ap = true;
	}

	cout << ans << endl;

	return 0;

}

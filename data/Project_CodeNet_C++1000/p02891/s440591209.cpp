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


ll f(string s){

	ll cnt = 0;
	ll tmp = 1;
	FOR(i,1,s.length()){
		if(s[i] == s[i-1]) tmp++;
		else{
			cnt += tmp/2;
			tmp = 1;
		}
	}
	if(tmp != 0) cnt += tmp / 2;
	return cnt;
}

int main(void){

	string s; cin >> s;
	int K; cin >> K;

	set<char> st;
	REP(i,s.length()){
		st.insert(s[i]);
	}

	ll ans = 0;
	if(st.size() == 1) ans =  s.length() * (ll)K / 2;
	else{
		ll prev = f(s);
		ll next = f(s+s);
		ans = prev + (K-1)*(next-prev);
	}

	cout << ans << endl;


	return 0;

}

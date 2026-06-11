#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

ll memo[30];
ll memo2[200005][30];

int main(){
	string s, t;
	cin >> s >> t;

	string ss = s + s;

	rep(i, 30) memo[i] = -1;

	for(ll i = ss.size() - 1; i >= 0; i--) {
		rep(j, 30) {
			if(memo[j] != -1) {
				memo2[i][j] = memo[j] - i;
			} else {
				memo2[i][j] = -1;
			}
		}
		ll ch = ss[i] - 'a';
		memo[ch] = i;
	}

	ll cur = -1;
	rep(i, s.size()) {
		if(t[0] == s[i]) {
			cur = i;
			break;
		}
	}
	if(cur == -1) {
		cout << "-1" << endl;
		return 0;
	}

	for(ll i = 1; i < t.size(); i++){
		ll ch = t[i] - 'a';
		if(memo2[cur%s.size()][ch] == -1) {
			cout << "-1" << endl;
			return 0;
		}
		cur += memo2[cur%s.size()][ch];
	}
	cout << cur + 1 << endl;
}


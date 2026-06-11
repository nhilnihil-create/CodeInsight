#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MK make_pair
#define REP(i, a, b) for (int i=a; i < b; i++)


bool sort_by(pi c, pi d){
	return c.S < d.S;
}

int main() {
	ll k;
	string s;
	cin >> s >> k;
	bool same = true;
	char a = s[0];
	ll ss = s.size();
	REP(i, 1, ss){
		if(s[i] != a){
			same = false;
			break;
		}
	}
	if(same) cout << ss*k/2;
	else{
		ll ans = 0, i = 1;
		while(i < ss){
			if(s[i] == s[i-1]){
				++i;
				++ans;
			}
			++i;
		}
		ans *= k;
		if(a == s[ss-1]){
			ll checkA = 0;
			ll checkB = 0;
			while(checkA < ss && s[checkA] == a) ++checkA;
			while(ss-checkB > 0 && s[ss-1-checkB] == a) ++checkB;
			ans -= ((checkA/2 + checkB/2 - (checkA+checkB)/2) * (k-1));
		}
		cout << ans;
	}
	

}

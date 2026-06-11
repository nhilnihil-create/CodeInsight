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
	string s;
	ll k, ans= 0, d = 0;
	cin >> s >> k;
	int i = 1;
	bool same = true;
	REP(i, 1, (int)s.size()){
		if(s[i] != s[0]){
			same = false;
			break;
		}
	}
	
	if(same){
		cout << (int)s.size()*k/2;
		return 0;
	}
	
	while(i < (int)s.size()){
		if(s[i] == s[i-1]){
			++d;
			++i;
		}
		++i;
	}
	ans = d*k;
	int ss = s.size()-1;
	if(s[0] == s[ss]){
		int a = 0;
		int b = 0;
		while(a <= ss && s[a] == s[0]) ++a;
		while(ss- b >= 0 && s[ss-b] == s[0]) ++b;
		ans -= ((a/2 +b/2 - (a+b)/2) * (k-1));
	}
		
	
	
	cout << ans;
	
}

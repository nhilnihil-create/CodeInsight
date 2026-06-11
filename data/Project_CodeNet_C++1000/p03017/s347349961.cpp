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
	int n, a, b, c, d;
	string s;
	cin >> n >> a >> b >> c >> d >> s;
	string ans = "Yes";
	s = "#" + s;
	REP(i, a, c){
		if(s[i] == '#' && s[i+1] == '#'){
			cout << "No";
			return 0;
		}
	}
	REP(i, b, d){
		if(s[i] == '#' && s[i+1] == '#'){
			cout << "No";
			return 0;
		}
	}
	
	if( d < c){
		ans = "No";
		for(int i = b; i <= d; i++){
			if(s[i-1] =='.' && s[i] =='.' && s[i+1] =='.') ans = "Yes";
		}
	}
	cout << ans;
		
	

}

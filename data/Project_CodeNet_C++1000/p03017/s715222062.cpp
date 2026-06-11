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
	s = "#" +s;
	char p;
	REP(i, a, c+1){
		if(i != a && p == '#' && s[i] == '#'){
			cout << "No";
			exit(0);
		}
		p = s[i];
	}
	REP(i, b, d+1){
		if(i != b && p == '#' && s[i] == '#'){
			cout << "No";
			exit(0);
		}
		p = s[i];
	}
	int m_c = 0;
	if( d < c){
		int t = 0;
		REP(i, b-1, d+2){
			if(s[i] == '.') ++t;
			else{ 
				m_c = max(m_c, t);
				t = 0;
			}
			m_c = max(m_c, t);
		}
		if(m_c < 3) ans = "No";
	}
	cout << ans;
		
	

}

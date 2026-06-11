#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
string s;
int n,a,b,c,d;
bool can(int start, int end) {
	for (int i = start; i < end; i++)
	{
		if (s[i] == '#' && s[i+1] == '#') return false;
	}
	return true;
} 

int main() {
	cin >>n>>a>>b>>c>>d;
	cin >> s;
	s = '#' + s + '#';
	
	if (!can(a,c) || !can(b,d)) {
		cout << "No" << endl;
		return 0;
	}

	if (c > d) {
		bool passing = false;
		for (int i = b; i <= d; i++)
		{
			if (s[i-1]=='.'&&s[i]=='.'&&s[i+1]=='.') passing = true;
		}
		if (!passing) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
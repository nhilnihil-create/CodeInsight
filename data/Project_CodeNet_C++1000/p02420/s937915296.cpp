#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
 
//const int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
//const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
 
int main()
{
	vector<string> ans;
	string E = "-";
	while (1){
		string s;
		int m;
		cin >> s;
		if (s == E) break;
		cin >> m;
		REP(i, m){
			int h;
			cin >> h;
			string tmp = s.substr(0, h);
			s.erase(0, h);
			s += tmp;
		}
		ans.push_back(s);
	}

	for (auto x : ans) cout << x << endl;
}


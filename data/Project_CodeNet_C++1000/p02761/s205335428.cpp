#include "bits/stdc++.h"

#define rep(i,n) for(int i = 0;i<n;i++)
#define cint(a) int a; cin >> a;
#define cstr(str) string str; cin >> str;


using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;	cin >> n;
	int m; cin >> m;
	vector<int> mem(n, -1);
	
	vector<pair<int, int>> sc(m);
	rep(i, m) cin >> sc[i].first >> sc[i].second;



	rep(i, 1000) {
		string str = to_string(i);
		if (str.size() != n) continue;
		bool flag = true;
		rep(j, m) {
			if (str[sc[j].first - 1] != sc[j].second + '0') {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << str << endl;
			return 0;
		}
	}
	
	cout << -1 << endl;


	return 0;
}

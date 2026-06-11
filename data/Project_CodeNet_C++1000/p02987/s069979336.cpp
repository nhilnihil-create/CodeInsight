#include <bits/stdc++.h>
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define sz(v) (int)(v).size()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	string ans = "No";
	if (s[0] == s[1] && s[1] != s[2] && s[2] == s[3]) ans = "Yes";
	cout << ans << '\n';

	return 0;
}

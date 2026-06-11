#include "bits/stdc++.h"

#define REP(i,n) for(int i=0;i<n;++i)
#define RREP(i,n) for(int i=n-1;i>=0;--i)
#define FOR(i,m,n) for(int i=m;i<n;++i)
#define RFOR(i,m,n) for(int i=n-1;i>=m;--i)
#define ALL(v) v.begin(),v.end()
#define PB(a) push_back(a)
#define INF 1000000001
#define MOD 1000000007
#define EPS 1e-9

const int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
const int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

typedef long long ll;
using namespace std;


pair<string,int> convert(string s, int l) {
	FOR(i, s.size(), l) s = '0' + s;
	vector<char> v(l);
	REP(i, l) v[i] = s[i];
	sort(ALL(v));
	int amin = 0;
	RREP(i, l) amin += (v[i]-'0') * int(pow(10, l-i-1));

	sort(ALL(v), greater<char>());
	int amax = 0;
	RREP(i, l) amax += (v[i]-'0') * int(pow(10, l-i-1));
	int a = amax - amin;
	string ret = "";
	int tmp = a;
	REP(i, l) {
		ret = char(tmp%10+int('0'))+ret;
		tmp /= 10;
	}
	return{ ret,a };
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int i, j;
	while (1) {
		string s;
		int l;
		cin >> s >> l;
		if (!l) break;
		vector<string> v;
		v.push_back(s);
		while (1) {
			string t = convert(s, l).first;
			int ans = convert(s, l).second;
			v.push_back(t);
			REP(k, v.size() - 1) {
				if (v[k] == t) {
					j = k;
					i = v.size();
					cout << j << " " << ans << " " << i - j-1 << endl;
					goto hoge;
				}
			}
			s = t;
		}
	hoge:;
	}
	return 0;
}
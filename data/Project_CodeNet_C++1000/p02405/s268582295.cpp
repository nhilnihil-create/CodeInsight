#include <bits/stdc++.h>
using namespace std;
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
#define P(x) cout << (x) << endl
#define p(x) cout << (x)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define VV(type, c, m, n, i) vector<vector<type>> c(m, vector<type>(n, i));
#define rep(i,a,n) for(int i=(a), i##_len=(n); i<i##_len; ++i)
#define rrep(i,a,n) for(int i=(a); i>n; --i)
#define len(x) ((int)(x).size())
#define mp make_pair
#define eb emplace_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
int main() {
	int H, W;
	string s[2];
	while(true) {
		cin >> H >> W;
		if (H == 0 && W == 0) break;
		s[0] = s[1] = "";
		rep(i, 0, W) {
			s[0] += i % 2 ? "." : "#";
			s[1] += i % 2 ? "#" : ".";
		}
		rep(i, 0, H) P(s[i%2]);
		P("");
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
#define P(x) cout << (x) << endl
#define p(x) cout << (x)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define vv(type, c, m, n, i) vector<vector<type>> c(m, vector<type>(n, i));
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
vi sk{0, 1, 2, 3, 4, 5, 6};
inline void roll(char c) {
	vi t(all(sk));
	switch (c) {
	case('E'):
		sk[1] = t[4];
		sk[4] = t[6];
		sk[6] = t[3];
		sk[3] = t[1];
		break;
	case('W'):
		sk[1] = t[3];
		sk[4] = t[1];
		sk[6] = t[4];
		sk[3] = t[6];
		break;
	case('N'):
		sk[1] = t[2];
		sk[2] = t[6];
		sk[6] = t[5];
		sk[5] = t[1];
		break;
	case('S'):
		sk[1] = t[5];
		sk[2] = t[1];
		sk[6] = t[2];
		sk[5] = t[6];
		break;
	}
}
int main() {
	rep(i, 1, 7) cin >> sk[i];
	string s; cin >> s;
	for(auto i : s) {
		roll(i);
	}
	P(sk[1]);
	return 0;
}
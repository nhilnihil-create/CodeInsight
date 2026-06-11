#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> si;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b)-1; i>=(a); --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define F first
#define S second
const int INF = 1000000007;
const int MOD = (int)1e9+7;
const long double PI = (acos(-1));
const long double EPS = 0.0000000001;
int dy[4] = {-2, -1};
int dx[4] = {-1, -2};

int n;
vi p;
vi idx;
multiset<int> s;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("in.txt", "r", stdin);
	cin >> n;
	p.resize(n);
	rep(i,0,n) {
		cin >> p[i];
	}
	idx.resize(n+1);
	rep(i,0,n) {
		idx[p[i]] = i;
	}

	ll total = 0;
	s.insert(n);
	s.insert(n);
	s.insert(-1);
	s.insert(-1);
	s.insert(idx[n]);
	per(i,1,n) {
		s.insert(idx[i]);
		auto it = s.find(idx[i]);
		int left = *(--it);
		int lleft = *(--it);
		++it;
		++it;
		int right = *(++it);
		int rright = *(++it);
		//cout << i << " : " << lleft << ' ' << left << ' ' << idx[i] << ' ' << right << ' ' << rright << endl;
		total += (long long)(left - lleft) * (right - idx[i]) * i;
		total += (long long)(idx[i] - left) * (rright - right) * i;
	}
	cout << total << endl;
	return 0;
}

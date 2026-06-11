#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define vc vector
#define sz(v) (int)(v).size()
#define pb push_back
#define FF first
#define SS second
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define pll pair<ll,ll>
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
typedef long double f80;
#define endl '\n'

const int mod = 1e9 + 7;
const int N = 505;

int c[N][N];

void go(vector<int> v,int d) {
	int n = sz(v);
	if(n <= 1) return;
	vector<int> v1, v2;
	int m = (n - 1) / 2;
	fr(i, 0, m) {
		v1.pb(v[i]);
	}
	fr(i, m + 1, n - 1) {
		v2.pb(v[i]);
	}
	for(int x : v1) {
		for(int y : v2) {
			c[x][y] = d;
		}
	}
	go(v1, d + 1);
	go(v2, d + 1);
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> v;
	fr(i, 1, n) {
		v.pb(i);
	}
	go(v, 1);
	fr(i, 1, n) {
		fr(j, i + 1, n) {
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define umap unordered_map
#define RESET   "\033[0m"
#define RED     "\033[31m"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const ll lINF = 1e18+7;
const int INF = 1e9+7;

template <class T> ostream& operator<<(ostream& s, const vector<T>& v) {
    for (size_t i = 0; i < v.size(); i++) s << v[i] << ' ';
    return s;
}

template <class T> istream& operator>>(istream& s, vector<T>& v) {
    for (size_t i = 0; i < v.size(); i++) s >> v[i];
    return s;
}


//########################################################################################





void solve(int CASE=0) {
	int n;
	cin >> n;
	vi v(n);
	map<int, queue<int>> m;
	cin >> v;

	sort(rall(v));
	m[v[1]].push(v[0]);
	ll sum = v[0];

	for (int i = 2; i < n; i++) {
		int l = prev(m.end())->F;
		int r = m[l].front();
		sum += l;
		m[min(v[i], l)].push(max(v[i], l));
		m[min(v[i], r)].push(max(v[i], r));
		if (i > 2) {
			m[l].pop();
			if (m[l].empty()) m.erase(l);
		}
	}
	cout << sum;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int TEST = 1;
    //cin >> q;
    for (int i = 1; i <= TEST; i++) 
		solve(i);
}

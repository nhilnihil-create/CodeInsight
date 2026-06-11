#include <bits/stdc++.h>

using namespace std;
#define NIL -1
#define ll long long
#define MAX 100
#define pb push_back

bool cmp(pair< int, int > p, pair< int, int > q)
{
	return p.first < q.first;
}

int main() {
	int n;
	cin >> n;
	vector< pair< int, int > > v;
	for(int i=1; i<=n; i++) {
		int x;
		cin >> x;
		v.pb(make_pair(x, i));
	}
	sort(v.begin(), v.end(), cmp);
	for(auto x: v) {
		cout << x.second << " ";
	}
    return 0;
}

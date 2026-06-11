#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pb push_back
#define endl '\n'
#define f first
#define s second
#define FAST cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
using namespace __gnu_pbds;

bool cmp(pair<int, string> a, pair<int, string> b) {
	if(a.f != b.f)
		return a.f > b.f;
	return a.s < b.s;
}

int32_t main() {

	int n;
	cin >> n;
	map<string, int> mapa;
	while(n--) {
		string s;
		cin >> s;
		mapa[s]++;
	}
	vector<pair<int, string>> v;
	for(auto i : mapa) 
		v.push_back({i.s, i.f});
	
	sort(v.begin(), v.end(), cmp);

	cout << v[0].s << endl;
	for(int i = 1; i < v.size(); i++) {
		if(v[i].f != v[i-1].f) break;
		cout << v[i].s << endl;

	}
}
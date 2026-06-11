#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define sz(v) (int)((v).size())
#define pb push_back

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<int> a(n);
	set<int> s;
	string ans = "YES\n";
	for (int i=0; i<n; i++){
		cin >> a[i];
		if (s.find(a[i]) != s.end())
			ans = "NO\n";
		else
			s.insert(a[i]);
	}
	cout << ans ;

}

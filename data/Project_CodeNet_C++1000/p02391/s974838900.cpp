#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<string> v = {"a < b", "a > b", "a == b"};

	int a, b; cin >> a >> b;

	if(a == b) cout << v[2] << endl;
	else cout << v[a > b] << endl;

	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//int n;
//vector< int > a(n);
//void solve() {
	//cin >> n;
	//a.resize(n);
	//for(auto& e:a) cin >> e;
//}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int t;
	//cin >> t;
	//while (t--) solve();
	int a,b;
	cin >> a >> b;
	b -= a-1;
	for(int i=0; i<2*a-1; i++) 
	{
		cout << b << ' ';
		b++;
	}
	cout << '\n';
	return 0;
}

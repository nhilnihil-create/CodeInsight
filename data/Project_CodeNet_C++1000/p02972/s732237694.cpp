#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 5;
int a[N], b[N];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef ONLINE_JUDGE
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);
#endif
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	vector<int> v;
	for(int i = n; i >= 1; i--){
		int total = 0;
		for(int j = i + i; j <= n; j += i)
			total += b[j];
		if(total % 2 != a[i] % 2)
			v.push_back(i), b[i] = 1;
	}
	cout << v.size() << '\n';
	for(auto &x : v)
		cout << x << ' ';
	return 0;
}

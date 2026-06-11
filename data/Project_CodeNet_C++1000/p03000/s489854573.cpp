#include <bits/stdc++.h>
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ll long long
#define pb push_back
#define iter std::vector<int>::iterator
 
int main() {
	ios_base ::sync_with_stdio(0);
	cin.tie(0);
 
	int n, x;
	cin >> n >> x;

	vector<int> vi (n);

	int res = 1, temp = 0;

	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		temp += a;

		if (temp <= x) res++;

	}

	cout << res;
	
 
	return 0;	
}

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vi vector<int>
#define INF 1000000000

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int S, W;
	cin >> S >> W;
	string safety = W >= S ? "unsafe" : "safe";

	cout << safety << endl;	

	return 0;
}

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, k; cin >> n >> k;
  	vector<int> p(n);
  	for (int &i : p) {
      	cin >> i;
    }
  	sort(p.begin(), p.end());
  	cout << accumulate(p.begin(), p.begin() + k, 0) << endl;
    return 0;
}

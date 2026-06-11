#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
typedef pair<int, int> pii;


int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
	cin >> n;
	map<int,int> bucket;
	for (int i = 0; i < n; ++i) {
	  int x; cin >> x;
	  bucket[x]++;
	}
	
	int distintos = 0;
	int etzor = 0;
	for (auto it : bucket) {
	  etzor ^= it.first;
	  distintos++;
	}
	if (distintos == 1) {
	  cout << (bucket[0] == n ? "Yes" : "No") << "\n";
	} else if (n % 3) {
	  cout << "No\n";
	} else if (distintos == 2) {
		cout << (bucket[0] == n/3 ? "Yes" : "No") << "\n";
	} else if (distintos == 3) {
	  bool flag = (etzor == 0);
	  for (auto it : bucket) {
	  	if (it.second != n/3) flag = false;
	  }
	  cout << (flag ? "Yes" : "No") << "\n";
	} else {
	  cout << "No\n";
	}
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200005], x, n;
int main() {
	cin >> n;
  	for (int i=1; i<n; i++) {
      cin >> x; a[x]++;
    }
  	for (int i=1; i<=n; i++) cout << a[i] << "\n";
}
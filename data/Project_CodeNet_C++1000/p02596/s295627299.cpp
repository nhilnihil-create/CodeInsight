#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int x=7%n;
	for(int i=1; i<=n; ++i) {
		if(x==0) {
			cout << i << "\n";
			return 0;
		}
		x=(x*10+7)%n;
	}
	cout << -1 << "\n";
}

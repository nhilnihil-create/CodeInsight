#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; cin>>n;

	for(int x=1; x<=n; x++) {
		if(floor(1.08 * x) == n) {
			cout<<x<<endl;
			return 0;
		}
	}

	cout<<":(\n";
	
	return 0;
}
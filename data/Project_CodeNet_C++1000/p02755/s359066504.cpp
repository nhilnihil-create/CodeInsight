// In the name of God

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int a, b;
	cin >> a >> b;

	if(a>b) swap(a, b);

	pair<int,int> x = make_pair(a, b);

	for(int i = 1; i <= 5000; i++) {
		pair<int,int> p = make_pair((i*8)/100, (i*10)/100);
		if(p == x) {
			cout << i;
			exit(0);
		}
	}

	cout << -1;
	

	return 0;
}

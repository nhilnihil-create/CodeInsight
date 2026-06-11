#include<bits/stdc++.h>
using namespace std;
int main() {
	int x; cin >> x;
	int cnt = x / 100;
	if(105 * cnt < x) cout << "0" << endl;
	else cout << "1" << endl;
	return 0;
}

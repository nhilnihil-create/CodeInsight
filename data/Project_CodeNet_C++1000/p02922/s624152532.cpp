#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int a, b;
	cin >> a >> b;
	int n = 1;
	int cnt = 0;
	while(n < b) {
		cnt += 1;
		n = (n - 1 + a);
	}
	cout << cnt;
	return 0;
}
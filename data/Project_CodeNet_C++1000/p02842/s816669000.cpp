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

	int n;
	cin >> n;
	int x1 = floor(n / 1.08);
	int x2 = ceil(n / 1.08);
	int n1 = floor(x1 * 1.08);
	int n2 = floor(x2 * 1.08);
	if(n1 == n) cout << x1;
	else if(n2 == n) cout << x2;
	else cout << ":(";
	return 0;
}

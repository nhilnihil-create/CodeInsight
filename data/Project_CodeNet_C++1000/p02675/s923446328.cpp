// In the name of God

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	n %= 10;

	if(n == 3) cout << "bon";
	else if(n==0||n==1||n==6||n==8) cout << "pon";
	else cout << "hon";
	
	return 0;
}

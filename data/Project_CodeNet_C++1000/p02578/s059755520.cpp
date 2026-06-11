#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, lst=0, a;
	ll s=0;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a;
		if(a>lst)
			lst = a;
		else
			s += lst - a;
	}
	cout << s;
	return 0;
} 
 

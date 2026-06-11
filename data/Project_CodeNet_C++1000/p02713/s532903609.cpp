#include <bits/stdc++.h>
using namespace std;

int _gcd(int a, int b){
	if (b == 0)
		return a;
	return _gcd(b, a%b);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	long long tot = 0;
	cin >> k;

	for (int a = 1; a <= k; a++){
		for (int b = 1; b <= k; b++){
			for (int c = 1; c <= k; c++){
				tot += _gcd(a, _gcd(b, c));
			}
		}
	}
	cout << tot << endl;
	return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
 
using namespace std;
 
typedef long long ll;
 
int main() {
	ll M;
	ll s = 0;
	ll s2 = 0;
	cin >> M;
	for (int i = 0; i < M; i++) {
		ll d, c;
		cin >> d >> c;
		s += d * c;
		s2 += c;
	}
	cout << (s - 1) / 9 + s2 - 1 << endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll s;
	ll oku = 1000000000;
	cin >> s;
	cout << "0 0 1000000000 1 " << (oku - (s % oku)) % oku << " " << (s + oku - 1) / oku << endl;

}
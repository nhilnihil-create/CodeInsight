#include<iostream> 
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)



int main() {
	long long int n, i = 0;
	long long int a, b, c = 0, k = 0;
	cin >> n >> k;
	if (k == 1 || k == n) {
		cout << 0 << endl;
		return 0;
	}
	if (n / k > 10000000000) {
		if (k / 10 > 1) {
			while (n >= 1000000000) {
				n -= k * 10000000;
			}
		}
		else {
			n -= k * 100000000000000000;
			while (n >= 100000000) {
				n -= k * 10000000;
		}
	
		}
		while (1) {
			i++;
			a = n - k;
			//cout << "a"<<a << endl;
			if (a < 0) {
				a = a * -2 + a;
				//cout <<"a2"<<a<< endl;
			}
			b = a - k;
			//cout <<"b"<< b << endl;
			if (b < 0) {
				b = b * -2 + b;
				//cout <<"b2"<< b << endl;
			}

			if (b < a && n != b) {
				n = b;
			}
			else {
				if (i == 1 && a < n) n = a;
				cout << k - n << endl;
				return 0;
			}
		}

	}
	//cout << n << endl;
	while (1) {
		i++;
		a = n - k;
		//cout << "a"<<a << endl;
		if (a < 0) {
			a = a * -2 + a;
			//cout <<"a2"<<a<< endl;
		}
		b = a - k;
		//cout <<"b"<< b << endl;
		if (b < 0) {
			b = b * -2 + b;
			//cout <<"b2"<< b << endl;
		}

		if (b < a && n != b) {
			n = b;
		}
		else {
			if (i == 1 && a < n) n = a;
			if (n - k)
				cout << n << endl;
			break;
		}
	}

	return 0;
}
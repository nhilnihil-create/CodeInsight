#include <iostream>
#include<vector>
#include<math.h>
using namespace std;
typedef long long ll;

int main() {
	ll n;
	cin >> n;
	vector<ll> A;
	for (int i = 0; i < 14; i++) {
		ll k = (ll)pow(26, 13 - i);
		if (n >= k) {
			A.emplace_back(n / k);
			n = n % k;
		}
		else if (A.size() != 0) {
			A.emplace_back(0);
		}
	}
	for (int i = 0; i < A.size()-1; i++) {
		if (A[A.size() - 1 - i] == 0) {
			A[A.size() - 2 - i]--;
		}
		else if (A[A.size() - 1 - i] == -1) {
			A[A.size() - 1 - i] = 25;
			A[A.size() - 2 - i]--;
		}
	}
	
	if (A[0] != 0) {
		for (int i = 0; i < A.size(); i++) {
			if (A[i] == 0)cout << "z";
			else if (A[i] == 1)cout << "a";
			else if (A[i] == 2)cout << "b";
			else if (A[i] == 3)cout << "c";
			else if (A[i] == 4)cout << "d";
			else if (A[i] == 5)cout << "e";
			else if (A[i] == 6)cout << "f";
			else if (A[i] == 7)cout << "g";
			else if (A[i] == 8)cout << "h";
			else if (A[i] == 9)cout << "i";
			else if (A[i] == 10)cout << "j";
			else if (A[i] == 11)cout << "k";
			else if (A[i] == 12)cout << "l";
			else if (A[i] == 13)cout << "m";
			else if (A[i] == 14)cout << "n";
			else if (A[i] == 15)cout << "o";
			else if (A[i] == 16)cout << "p";
			else if (A[i] == 17)cout << "q";
			else if (A[i] == 18)cout << "r";
			else if (A[i] == 19)cout << "s";
			else if (A[i] == 20)cout << "t";
			else if (A[i] == 21)cout << "u";
			else if (A[i] == 22)cout << "v";
			else if (A[i] == 23)cout << "w";
			else if (A[i] == 24)cout << "x";
			else if (A[i] == 25)cout << "y";
		}
	}
	else{
		for (int i = 1; i < A.size(); i++) {
			if (A[i] == 0)cout << "z";
			else if (A[i] == 1)cout << "a";
			else if (A[i] == 2)cout << "b";
			else if (A[i] == 3)cout << "c";
			else if (A[i] == 4)cout << "d";
			else if (A[i] == 5)cout << "e";
			else if (A[i] == 6)cout << "f";
			else if (A[i] == 7)cout << "g";
			else if (A[i] == 8)cout << "h";
			else if (A[i] == 9)cout << "i";
			else if (A[i] == 10)cout << "j";
			else if (A[i] == 11)cout << "k";
			else if (A[i] == 12)cout << "l";
			else if (A[i] == 13)cout << "m";
			else if (A[i] == 14)cout << "n";
			else if (A[i] == 15)cout << "o";
			else if (A[i] == 16)cout << "p";
			else if (A[i] == 17)cout << "q";
			else if (A[i] == 18)cout << "r";
			else if (A[i] == 19)cout << "s";
			else if (A[i] == 20)cout << "t";
			else if (A[i] == 21)cout << "u";
			else if (A[i] == 22)cout << "v";
			else if (A[i] == 23)cout << "w";
			else if (A[i] == 24)cout << "x";
			else if (A[i] == 25)cout << "y";
		}
	}

	
	return 0;
}
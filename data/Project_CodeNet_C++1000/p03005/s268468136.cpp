#include<iostream>
#include<string>
#include<algorithm>	
#include<cmath>
using namespace std;
int main() {
	long long n, a; cin >> n >> a;
	if (a == 1) {
		cout << 0 << endl;
	}
	else {
		cout << n - a << endl;
	}
	cin >> n;
}
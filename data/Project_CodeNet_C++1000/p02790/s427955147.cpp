#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
	string a,b;
	cin >> a>>b;
	string ao, bo;
	rep(i, atoi(b.c_str())) {
		ao += a;
	}
	rep(i, atoi(a.c_str())) {
		bo += b;
	}
	
	if (ao >= bo) {
		cout << bo << endl;
	}
	else {
		cout << ao << endl;
	}
}

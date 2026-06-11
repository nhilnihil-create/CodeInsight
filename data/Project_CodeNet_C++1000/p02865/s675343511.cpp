#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>

#define rep(i,n) for(int i=0;i<n;i++)
#define llint long long int

using namespace std;

int main() {
	int a;
	cin >> a;
	if (a % 2 == 0) {
		cout << a / 2 - 1 << endl;
	}
	else {
		cout << a / 2 << endl;
	}
	return 0;
}
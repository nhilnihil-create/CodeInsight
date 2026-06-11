#include<iostream>
using namespace std;
int main() {

	//B
	long long int a, b, v, w, t;
	cin >> a >> v;
	cin >> b >> w;
	cin >> t;
	if (v <= w) {
		cout << "NO" << endl;
		return 0;
	}
	if (abs(a - b) <= t * (v - w)) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;

	//A
	/*string s;
	cin >> s;
	int i;
	for (i = 0; i < 3; i++) {
		cout << s[i];
	}
	cout << endl;
	return 0;
	*/
}
#include<iostream>
using namespace std;
int main() {

	//B
	int n, l;
	cin >> n >> l;
	int k = n * l + n * (n - 1) / 2;
	//cout << k;
	int i;
	int min = l;
	for (i = 0; i < n; i++) {
		if (abs(l + i) < abs(min)) {
			min =  l + i;
		}
	}
	cout << k - min << endl;
	return 0;

	//A
	/*
	string s;
	cin >> s;
	for (int i = 0; i < 3; i++) {
		if (s[i] == s[i + 1]) {
			cout << "Bad" << endl;
			return 0;
		}
	}
	cout << "Good" << endl;
	return 0;
	*/
}
#include<iostream>
using namespace std;
int main() {
	int n;
	string s[50];
	int t[50];
	cin >> n;
	int i;
	for (i = 0; i < n; i++) {
		cin >> s[i] >> t[i];
	}
	string x;
	cin >> x;
	int k;
	for (i = 0; i < n; i++) {
		if (s[i] == x) {
			k = i+1;
			
			break;
		}
	}
	int counter = 0;
	for (i = k; i < n; i++) {
		counter = counter + t[i];
	}
	cout << counter << endl;
	return 0;

}
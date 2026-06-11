#include <iostream>
using namespace std;
int main () {
	int N;
	cin >> N;
	string s;
	cin >> s;
	if (N%2==0) {
		int sum=0;
		for (int i=0, j=N/2; j<N; i++, j++) {
			if (s[i]==s[j]) {
				sum++;
			}
		}
		if (sum==N/2) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	else {
		cout << "No" << endl;
	}
}
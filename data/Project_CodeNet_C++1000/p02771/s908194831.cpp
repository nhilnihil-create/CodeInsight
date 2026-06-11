#include<iostream>
#include<algorithm>
using namespace std;

string s[200000];
int main() {
	
	int a, b, c;
	cin >> a >> b >> c;
	if (a == b && b != c) {
		cout << "Yes" << endl;
	}
	else if (b == c && c!= a) {
		cout << "Yes" << endl;
	}
	else if (c == a && a != b) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;

	//B
	/*int n;
	int a[100];
	cin >> n;
	int i;
	for (i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] % 2 == 0) {
			if (a[i] % 3 == 0) {

			}
			else if (a[i] % 5 == 0) {

			}
			else {
				cout << "DENIED" << endl;
				return 0;
			}
		}
	}
	cout << "APPROVED" << endl;
	return 0;
	*/
	//C
	/*int i, n;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> s[i];
	}
	sort(s, s + n);
	//cout<< endl << "sort" << endl;
	//for (i = 0; i < n; i++) {
	//	cout << s[i] << endl;
	//}
	//cout << "sort" << endl << endl;
	string t;
	t = s[0];
	int counter = 1, maxc = 0;
	for (i = 1; i < n; i++) {
		if (s[i] == t) {
			counter++;
		}
		else {
			t = s[i];
			if (counter > maxc)maxc = counter;
			counter = 1;
		}

	}
	if (counter > maxc)maxc = counter;

	t = s[0]; counter = 1;
	for (i = 1; i < n; i++) {
		if (s[i] == t) {
			counter++;
		}
		else {
			t = s[i];
			if (counter  == maxc)cout << s[i-1] << endl;
			counter = 1;
		}

	}
	if (counter == maxc) {
		cout << s[n - 1] << endl;
	}
	return 0;*/

	//D
	/*int n,k;
	cin >> n >> k;
	int i;
	long long int a[200000];
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}*/
	//E
	/*string s;
	cin >> s;
	int i, j;
	int flag = 0;
	long long int sum = 0;
	for (i = s.size() - 1; i >= 0; i--) {
		j = s[i] - '0' + flag;
		if (j == 10) {
			j = 0;
			flag = 1;
		}
		else {
			flag = 0;
		}
		if (j <= 5) {
			sum = sum + j;
		}
		else {
			sum = sum + 10 - j;
			flag = 1;
		}
	}
	cout << sum + flag << endl;
	return 0;*/


}
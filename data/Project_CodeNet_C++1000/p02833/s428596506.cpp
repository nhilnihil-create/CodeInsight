#include<iostream>
using namespace std;
long long int gcd(long long int a, long long int b);
int a[200000];
int main() {
	
	//E
	long long int N;
	cin >> N;
	long long int counter = 0;
	if (N % 2 == 1) {
		cout << 0 << endl;
		return 0;
	}
	else {
		if (N == 0) {
			cout << 0 << endl;
			return 0;
		}
		else {
			N = N - (N % 10);
			N = N / 10;
			counter = counter + N;
			while (N > 0) {
				N = N - (N % 5);
				N = N / 5;
				counter = counter + N;
			}
			cout << counter << endl;
			return 0;
		}
	}
	
	
	//D

	/*int n;
	cin >> n;
	int i;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	int counter = 0;
	int seek = 1;
	for (i = 0; i < n; i++) {
		if (a[i] == seek) {
			counter++;
			seek++;
		}
	}
	if (counter == 0) {
		cout << -1 << endl;
		return 0;
	}
	cout << n - counter << endl;
	return 0;*/


	//C
	/*long long int A, B;
	cin >> A >> B;
	cout <<  A * B / gcd(A, B) << endl;
	return 0;*/

	//B
	/*int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	int i;
	for (i = 0; i < n; i++) {
		cout << s[i];
		cout << t[i];
	}
	cout << endl;
	return 0;*/
}
long long int gcd(long long int a,long long  int b) {
	if (a == 0) {
		return b;
	}
	else if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a%b);
	}
}
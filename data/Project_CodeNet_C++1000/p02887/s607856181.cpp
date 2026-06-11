#include <iostream>
using namespace std;
int main () {
	int N;
	cin >> N;
	string s;
	cin >> s;
	int sum=1;
	for (int i=1; i<N; i++) {
		if (s[i]!=s[i-1]) {
			sum++;
		}
	}
	cout << sum << endl;
}
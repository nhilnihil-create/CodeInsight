#include<iostream>
#include<string>
using namespace std;

int main() {
	int all = 0, ans = 0;
	cin >> all;

	string str;
	cin >> str;

	for (int i = 0; i < all - 2; i++) {

		if (str[i] == 'A') {
			if (str[i + 1] == 'B') {
				if (str[i + 2] == 'C') {
					ans++;
				}
			}
		}
	}

	cout << ans << endl;
}
#include<iostream>
#include<string>
using namespace std;

int main() {
	string x;

	for (;;) {

		int ans=0;

		cin >> x;
		if (x == "0")break;

		for (int i = 0; i < x.size(); i++) {
			ans += x[i]-'0';
		}
		cout << ans << endl;
	}
	return 0;
}
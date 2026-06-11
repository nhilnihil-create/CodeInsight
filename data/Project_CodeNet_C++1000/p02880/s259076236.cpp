
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	string ans = "No";
	for (int i = 1; i <= 9; i++) {
		if (ans == "Yes") {
			break;
		}
		else {
			for (int j = 1; j <= 9; j++) {
				if (i * j == n) {
					ans = "Yes";
					break;
				}
			}
		}
	}

	cout << ans << endl;
	return 0;

}
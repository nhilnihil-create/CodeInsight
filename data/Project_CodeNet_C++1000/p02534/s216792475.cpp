#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int K;
	cin >> K;
	string ans = "";
	for (int i = 0; i < K; ++i)
		ans = ans + "ACL";
	cout << ans << '\n';
	return 0;
}

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int K;
	string S, ans;
	cin >> K;
	cin >> S;
	if (K < S.size()) {
		ans = S.substr(0, K) + "...";
	}
	else {
		ans = S;
	}
	cout << ans << endl;
}


#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	string S, T;
	cin >> S >> T;

	if (S.length() + 1 != T.length()) {
		cout << "No" << endl;
		return 0;
	}

	for (int i = 0; i < S.length(); i++) {
		if (S[i] != T[i]) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;


}

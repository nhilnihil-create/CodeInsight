#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	string S;
	cin >> S;

	for (int i = 0; i < S.length() - 1; i++) {
		if (S[i] == S[i + 1]) {
			cout << "Bad" << endl;
			return 0;
		}
	}
	cout << "Good" << endl;
}

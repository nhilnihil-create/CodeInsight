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

	int total = 0;
	for (int i = 0; i < S.length(); i++) {
		total += S[i]-'0';
	}

	if (total % 9 == 0) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}

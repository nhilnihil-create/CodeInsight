#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

int main()
{
	string S;
	cin >> S;

	string rev_S = S;
	reverse(rev_S.begin(), rev_S.end());

	if (rev_S != S) {
		cout << "No" << endl;
		return 0;
	}

	string S1 = S.substr(0, (S.length() - 1) / 2);
	string S2 = S.substr(((S.length() + 3) / 2)-1, (S.length() - 1) / 2);
	//cout << "S1:" << S1 << endl;
	//cout << "S2:" << S2 << endl;

	string rev_S1 = S1;
	if (rev_S1 != S1) {
		cout << "No" << endl;
		return 0;
	}

	string rev_S2 = S2;
	if (rev_S2 != S2) {
		cout << "No" << endl;
		return 0;
	}

	if (S1 != S2) {
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;
}





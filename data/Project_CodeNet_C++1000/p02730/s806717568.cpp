#include "bits/stdc++.h"

using namespace std;

int main() {
	string S;
	cin >> S;
	string rS = S;
	reverse(rS.begin(),rS.end());
	string S1 = S.substr(0,(S.size()-1)/2);
	string rS1 = S1;
	reverse(rS1.begin(), rS1.end());
	string S2 = S.substr((S.size() + 1) / 2, (S.size() - 1) / 2);
	string rS2 = S2;
	reverse(rS2.begin(), rS2.end());
	if (S != rS) {
		cout << "No" << endl;
		return 0;
	}
	if (S1 != rS1) {
		cout << "No" << endl;
		return 0;
	}
	if (S2 !=rS2) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	return 0;
}
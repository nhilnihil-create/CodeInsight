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

	for (int i = 0; i < S.length(); i++) {
		if ((i + 1) % 2 == 1) {
			//奇数文字目
			if (S[i] == 'L') {
				cout << "No" << endl;
				return 0;
			}
		}
		else {
			//偶数文字目
			if (S[i] =='R') {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;

}

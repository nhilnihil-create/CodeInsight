#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
const int mod = 1000000007;
#define ll long long


int main()
{
	string S;
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		if ((i % 2 == 0 && S[i] == 'L') || (i % 2 == 1 && S[i] == 'R')) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}

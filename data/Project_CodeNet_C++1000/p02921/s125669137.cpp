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

	int count = 0;
	for (int i = 0; i < 3; i++) {
		if (S[i] == T[i]) {
			count++;
		}
	}
	cout << count << endl;
}

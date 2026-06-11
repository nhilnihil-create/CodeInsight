#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <ctype.h>
#include <stdlib.h>
#include <map>
using namespace std;

int main()
{
	int K;
	cin >> K;
	string S;
	cin >> S;

	if (S.length() <= K) {
		cout << S << endl;
	}
	else {
		string ans = "";
		for (int i = 0; i < K; i++)
		{
			ans += S[i];
		}
		ans += "...";
		cout << ans << endl;
	}
}

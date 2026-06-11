#include <iostream>
#include <string> 
#include <algorithm>
using namespace std;

int main()
{
	string S, T;
	cin >> S >> T;

	int cnt = 0;
	for (int i = 0; i < S.length(); ++i)
		if (S[i] != T[i])++cnt;

	cout << cnt;
}

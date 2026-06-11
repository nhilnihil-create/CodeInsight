#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;


void func()
{
	string S, T;
	cin >> S;
	cin >> T;

	if (1 > S.length() || S.length() > 10)
	{
		cout << "No\n";
		return;
	}

	if(S.length() + 1 != T.length())
	{
		cout << "No\n";
		return;
	}

	for (int i = 0; i < S.length(); ++i)
	{
		if(!islower(S[i]) || S[i] != T[i])
		{
			cout << "No\n";
			return;
		}
	}

	if (!islower(*T.rbegin()))
	{
		cout << "No\n";
		return;
	}

	cout << "Yes\n";
	return;
}

int main() {

//	while (1)
		func();
	return 0;
}

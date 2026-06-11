#include <iostream>
#include <string>
using namespace std;

int main()
{
	unsigned int K;
	cin >> K;

	string S;
	cin >> S;

	if (S.length() <= K)
	{
		cout << S << endl;
	}
	else
	{
		string sdot = S.substr(0, K);
		sdot.append("...");
		cout << sdot << endl;
	}

	return 0;
}
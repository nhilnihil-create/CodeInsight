#include <iostream>
#include <string>

using namespace std;

int main()
{
	int answer = 0;
	string S, T;
	cin >> S >> T;
	for (int count = 0; count < 3; count++)
	{
		if (S.at(count) == T.at(count))
		{
			answer++;
		}
	}
	cout << answer << endl;
}
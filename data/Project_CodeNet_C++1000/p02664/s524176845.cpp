#include<iostream>
#include<string>
using namespace std;

int main()
{
	string S;
	cin >> S;
	int i = 0;

	while(S[i] != '\0')
	{
		if(S[i] == '?')
		{
			S[i] = 'D';
		}
		i++;
	}
	cout << S;
	return 0;
}
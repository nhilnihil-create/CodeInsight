#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	int K;
	int i = 0;
	cin >> K >> s;
	while (s[i])
	{
		i++;
	}
	if (i>K)
	{
		for (int d = 0; d < K; d++)
		{
			cout << s[d];
		}
		cout << "...";
	}
	else
	{
		cout << s;
	}
}


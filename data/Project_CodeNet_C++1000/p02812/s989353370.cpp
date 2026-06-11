#include<iostream>
using namespace std;

int main()
{
	int n, cnt = 0;
	cin >> n;
	char str[n];

	cin >> str;
	for(int i = 0; i < n; i++)
	{
		if(str[i]=='A')
		{
			if(str[i+1]=='B')
			{
				if(str[i+2]=='C')
				{
					cnt += 1;
					i+= 2;
				}
			}
		}
	}

	cout << cnt;
}

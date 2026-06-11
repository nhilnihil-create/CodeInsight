#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t;
	while (scanf("%d", &t) != EOF)
	{
		int count = 0, i;
		char str[51];
		for (i=0; i<t; i++)
			cin>>str[i];
		for (i=0; i<t;)
		{
			if (str[i] == 'A' && str[i+1] == 'B' && str[i+2] == 'C')
			{
				count++;
				i+=2;
			}
			else
				i++;
		}
		cout<<count<<endl;
	}	
	return 0;
}
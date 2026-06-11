#include<bits/stdc++.h>

using namespace std;

string s;
int ans; 
int main()
{
	cin >> s;
	for(int i = 0; i < s.size(); i++)
	{
		ans += (s[i] - '0');
	}
	if(ans % 9 == 0)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	return 0;
}
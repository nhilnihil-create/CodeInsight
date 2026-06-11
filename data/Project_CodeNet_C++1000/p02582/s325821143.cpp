#include <bits/stdc++.h>
using namespace std;

int main()
{
	int currStreak = 0, maxStreak = 0;
	
	string s;
	cin >> s;
	
	for(int i = 0; i < (int)(s.length()); i++)
	{
		if(s[i] == 'R')
		{
			currStreak++;
		}
		
		else
			currStreak = 0;
			
		maxStreak = max(maxStreak, currStreak);
	}
	
	printf("%d", maxStreak);
}

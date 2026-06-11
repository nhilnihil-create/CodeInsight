#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	
	string s = "";
	int rCount = 0, ans = 0;
	for(int i = 1; i <= N; i++)
	{
		char currChar;
		scanf(" %c", &currChar);
		s += currChar;
		
		if(currChar == 'R')
			rCount++;
	}
	
	for(int i = 0; i < rCount; i++)
	{
		if(s[i] != 'R')
			ans++;
	}
	
	printf("%d", ans);
}

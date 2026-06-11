//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>

#define REP(i, max)	for(int i = 0, iMax = max; i < iMax; i ++)
using namespace std;

int main(int args, char **ppArgs)
{
	int numTables;
	
	while(::scanf("%d", &numTables), numTables)
	{
		// Input conversion tables
		map<char, char>	conversionMap;
		char	from, to;
		REP(i, numTables)	cin >> from >> to,	conversionMap[from]	= to;
		
		// Input text
		int textLen;
		::scanf("%d", &textLen);
		string	text(textLen, 0);
		REP(i, text.size())
		{
			char ch;
			cin >> ch;
			text[i]	= conversionMap.count(ch) ? conversionMap[ch] : ch;
		}
		::puts(text.c_str());	
	}
}
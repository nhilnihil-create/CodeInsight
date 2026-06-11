#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
#include <utility>
#include <string>
#include <ctype.h>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <functional>

using namespace std;

#define FOR(i,k,n) for(int i = (k); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define INF 114514810
#define ll long long
#define scanf scanf_s

string s;

int main()
{
	while (getline(cin, s))
	{
		if (s[0] == '.') break;
		vector<char> v;
		REP(i,105)v.push_back('0');
		bool f = true;
		REP(i, s.size())
		{
			if (s[i] == '[') v.push_back('[');
			if (s[i] == '(') v.push_back('(');
			if (s[i] == ']')
			{
				if (v.back() == '[')
				{
					v.pop_back();
				}
				else f = false;
			}
			if (s[i] == ')')
			{
				if (v.back() == '(')
				{
					v.pop_back();
				}
				else f = false;
			}
		}
		if (f&&v.back()=='0') cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}
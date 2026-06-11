#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdio.h>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <map>
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
//#define scanf scanf_s

int main()
{
	string s;
	while (getline(cin, s))
	{
		if (s[0] == '.') break;
		vector<int> v;
		v.push_back(100);
		REP(i, s.size())
		{
			if (s[i] == '(') v.push_back(0);
			if (s[i] == '[') v.push_back(1);
			if (s[i] == ')')
			{
				int n = v.back();
				v.pop_back();
				if (!(n == 0))
				{
					cout << "no" << endl;
					goto end;
				}
			}
			if (s[i] == ']')
			{
				int n = v.back();
				v.pop_back();
				if (!(n == 1))
				{
					cout << "no" << endl;
					goto end;
				}
			}
		}
		if (v.back() == 100) cout << "yes" << endl;
		else cout << "no" << endl;
	end:;
	}
	return 0;
}
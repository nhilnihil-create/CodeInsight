#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <cstdio>
#define rep(i, j) for(int i = 0; i < j; i++)
#define all(i) i.begin(), i.end()
using namespace std;
int main()
{
	string str; while (getline(cin, str) && str[0] != '.' && str.size() != 1)
	{
		int id = 0;
		stack<int> stck;
		rep(i, (int)str.size())
		{
			switch (str[i])
			{
				case '(':	stck.push(1);	break;
				case '[': stck.push(2); break;
				case ')': 
					if (stck.size() == 0) { id = 1; }
					else if (stck.top() == 1) { stck.pop(); }
					else { id = 1; } break;
				case ']': 
					if (stck.size() == 0) { id = 1; }
					else if (stck.top() == 2) { stck.pop(); }
					else { id = 1; } break;
			}
		}
		if (stck.size() != 0 || id == 1) { printf("no\n"); }
		else { printf("yes\n"); }
	}
	return 0;
}
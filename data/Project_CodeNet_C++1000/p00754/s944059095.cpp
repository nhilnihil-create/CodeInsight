#include <iostream>
#include <climits>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

char s[1000];

string solve()
{
	stack<char> st;

	for(int i = 0; s[i] != '.'; i++)
	{
		if( s[i] == '(' )
		{
			st.push('(');
		}
		else if( s[i] == '[' )
		{
			st.push('[');
		}
		else if( s[i] == ')' )
		{
			if( !st.empty() && st.top() == '(' )
				st.pop();
			else
				st.push(')');
		}
		else if( s[i] == ']' )
		{
			if( !st.empty() && st.top() == '[' )
				st.pop();
			else
				st.push(']');
		}
	}

	if( st.empty() && st.empty() )
		return "yes";
	else 
		return "no";
}

int main()
{
	while( cin.getline(s,sizeof(s)), s[0] != '.' )
		cout << solve() << endl;

	return 0;
}
#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isbracket(char c)
{
    return (c == '[' || c == ']' || c =='(' || c == ')');
}


string rem(string str)
{
    string res;

    for(int i=0; i<str.size(); i++)
	if(isbracket(str[i])) res += str[i];

    return res;
    
}

bool solve(string in)
{
    string s = rem(in);
    stack<char> brackets;
    brackets.push('!');
    
    for(int i=0; i<s.size(); i++) {
	char c = s[i];

	if( c == '(' || c == '[' )
	    brackets.push(c);
	else {
	    if ( c == ')' && (brackets.top() != '(') ) return false;
	    if ( c == ']' && (brackets.top() != '[') ) return false;

	    brackets.pop();
	}
    }

    if ( brackets.size() != 1 ) return false;

    return true;
}

int main()
{
    string str;
    
    while(1) {
	getline(cin, str);

	if ( str.size() == 1 ) break;

	bool res = solve(str);

	cout << (res ? "yes" : "no") << endl;
    }
    
}


	    
	
	
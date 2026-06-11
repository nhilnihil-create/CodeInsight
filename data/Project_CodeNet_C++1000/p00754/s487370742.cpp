#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<stack>
using namespace std;

stack<char> st;

char str[514];
int slen;

int main() {
	int i;
	while( gets(str) ) {
		if ( str[0] == '.' && str[1] == '\0' )
			break;
		slen = strlen(str);
		for( i = 0; i < slen; i++ ) {
			if ( str[i] == '(' || str[i] == '[' )
				st.push(str[i]);
			if ( str[i] == ')' ) {
				if ( st.empty() || st.top() != '(' )
					break;
				st.pop();
			}
			if ( str[i] == ']' ) {
				if ( st.empty() || st.top() != '[' )
					break;
				st.pop();
			}
		}
		if ( i == slen && st.empty() )
			cout << "yes" << endl;
		else
			cout << "no" << endl;
		while(!st.empty())
			st.pop();
	}
	return 0;
}
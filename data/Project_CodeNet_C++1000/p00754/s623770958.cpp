#include <iostream>
#include <string>
//#include <stack>

using namespace std;

char stack[101];
int pointer;

char pop( void )
{
	if(pointer > 0) return stack[--pointer];
	else return 'x';
}
void push( char c )
{
	if(pointer < 101) stack[pointer++] = c;
}
int main( void )
{
	string in;
	while(getline(cin, in), in[0] != '.') {
		pointer = 0;
		bool hit = true;
		int len = in.size();
		for(int i=0; i < len; ++i) {
			if(in[i] == '(' || in[i] == '[') {
				push(in[i]);
			}
			else if(in[i] == ')') {
				if('(' != pop()) hit = false;
			}
			else if(in[i] == ']') {
				if('[' != pop()) hit = false;
			}
		}
		if(!pointer && hit)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
}
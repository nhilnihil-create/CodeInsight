#include <iostream>
#include <string>

using namespace std;

int main( void )
{
	string in;
	char stack[101];
	while(getline(cin, in), in[0] != '.') {
		int pointer = 0;
		bool hit = true;
		int len = in.size();
		for(int i=0; i < len; ++i) {
			if(in[i] == '(' || in[i] == '[') {
				stack[pointer++] = in[i];
			}
			else if(in[i] == ')') {
				if(!pointer || '(' != stack[--pointer]) hit = false;
			}
			else if(in[i] == ']') {
				if(!pointer || '[' != stack[--pointer]) hit = false;
			}
		}
		if(!pointer && hit)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
}
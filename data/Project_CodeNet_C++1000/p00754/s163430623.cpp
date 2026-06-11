#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

int main()
{
	while(true){
		char line[105];
		cin.getline(line, sizeof(line));
		if(line[0] == '.'){break;}
		else{
			stack<char> s;
			if( ( line[0] == '(' ) || ( line[0] == '[' )||( line[0] == ')' ) || ( line[0] == ']' ) ){
				s.push(line[0]);
			}
			for(int i=1; ;i++){
				char k = ' ';
				if(!s.empty()){
					k = s.top();
				}
				if(line[i] == '.'){break;}
				else if( ( line[i] == ')' ) && ( k == '(' ) ){
					s.pop();
				}
				else if(( line[i] == ']' )&&( k == '[' )){
					s.pop();
				}
				else if( ( line[i] == '(' ) || ( line[i] == '[' ) ){
					s.push(line[i]);
				}
				else if(( line[i] != '(' ) && ( line[i] != ')' ) && ( line[i] != '[' ) && ( line[i] != ']' )){
					;
				}
				else if( ( line[i] == ')' ) || ( line[i] == ']' ) )
				{
					s.push(line[i]);
				}
				else{;}
			}
			if(s.empty()){
				cout << "yes" << endl;
			}
			else{cout << "no" << endl;}
		}
	}

	return 0;
}
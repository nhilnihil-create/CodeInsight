#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <math.h>

#define PREP(i, m, n) for(int i = m; i < n; i++)
#define MREP(i, m, n) for(int i = m - 1; i >= n; i--)
using namespace std;

int main(){
	string input;
	while(getline(cin, input)){
		stack<char> bracket;
		if(input.size() == 1 && input[0] == '.') break;
		for(int i = 0; i < input.size(); i++){
			if(input[i] == '(' || input[i] == '[') bracket.push(input[i]);
			if(bracket.size() == 0){
				if(input[i] == ')' || input[i] == ']'){
					bracket.push(input[i]);
					break;
				}
				continue;
			}
			if(input[i] == ')'){
				if(bracket.top() == '(') bracket.pop();
				else break;
			}
			else if (input[i] == ']'){
				if(bracket.top() == '[') bracket.pop();
				else break;
			}
		}
		cout << (!bracket.size() ? "yes" : "no") << endl; 
	}
	return 0;
}
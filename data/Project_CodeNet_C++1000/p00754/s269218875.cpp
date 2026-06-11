#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int main(){

	char buf[300];
	stack<char> S;
	bool Broken;

	while(true){
		fgets(buf,300,stdin);
		if(buf[0] == '.' && buf[1] == '\n')break;

		Broken = false;

		for(int i = 0; buf[i] != '\0' && buf[i] != '\n'; i++){
			if(buf[i] == '('){
				S.push('(');
			}else if(buf[i] == '['){
				S.push('[');
			}else if(buf[i] == ')'){
				if(S.empty() == true || S.top() != '('){
					Broken = true;
					break;
				}else{
					S.pop();
				}
			}else if(buf[i] == ']'){
				if(S.empty() == true || S.top() != '['){
					Broken = true;
					break;
				}else{
					S.pop();
				}
			}
		}

		if(!S.empty()){
			Broken = true;
			while(!S.empty())S.pop();
		}

		if(!Broken)printf("yes\n");
		else{
			printf("no\n");
		}
	}

	return 0;
}
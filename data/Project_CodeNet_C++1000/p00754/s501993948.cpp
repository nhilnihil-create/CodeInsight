#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void judge(string str){
	vector<char> B;
	B.push_back('$');

	for(int i=0;i<str.length();i++){
		if(str[i] == '(')
			B.push_back('(');
		else if(str[i] == '[')
			B.push_back('[');
		else if(str[i] == ')')
			if(B[B.size()-1] == '(')
				B.pop_back();
			else
				B.push_back(')');
		else if(str[i] == ']')
			if(B[B.size()-1] == '[')
				B.pop_back();
			else
				B.push_back(']');
	}

	if(B.size() == 1)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
}

int main(){
	while(1){
		string str;
		getline(cin, str);
		if(str == ".")
			break;

		judge(str);
	}

	return 0;
}
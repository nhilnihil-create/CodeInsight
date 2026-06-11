#include <bits/stdc++.h>
using namespace std;


string str;
int idx;
char c;

bool next(){
	if(idx < str.length()){
		c = str[idx++];
		return true;
	}else{
		return false;
	}
}

bool recur(){
	while(1){
		if(c == '('){
			if(!next()) return false;
			if(!recur()) return false;
			if(c != ')') return false;
		}else if(c == '['){
			if(!next()) return false;
			if(!recur()) return false;
			if(c != ']') return false;

		}else if(c == ')' || c == ']'){
			return true;
		}

		if(!next()) return true;
	}
}

int main(){
	while(getline(cin, str), str != "."){
		idx = 0;
		next();
		cout << (recur() && idx == str.length() ? "yes" : "no") << endl;

	}
}
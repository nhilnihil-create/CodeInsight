#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

char buf[109];

bool solve(){
	vector<char> st;
	for(int i=0; buf[i]!='.'; i++){
		char c = buf[i];
		if(c == '(' || c == '['){
			st.push_back(c);
		}
		else if(c == ')' || c == ']'){
			if(st.empty()) return false;
			else if(c == ')' && st.back() == '(') st.pop_back();
			else if(c == ']' && st.back() == '[') st.pop_back();
			else return false;
		}
	}
	return st.empty();
}

int main(){
	while(scanf("%[^\n]%*c", buf), strcmp(buf,".")){
		puts(solve()?"yes":"no");
	}
	return 0;
}
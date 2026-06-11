#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

char x;
vector<string> ans;
vector<char> stk;
int main(){
	bool ok = true;
	while(~scanf("%c", &x)){
		if(x == '.'){
			if(!stk.empty())ok = false;
			if(ok)ans.push_back("yes");
			else ans.push_back("no");
			ok = true;
			stk.clear();
		}
		if(x == '('){
			stk.push_back(x);
		}
		if(x == '['){
			stk.push_back(x);
		}
		if(x == ')'){
			if(!stk.empty() && stk.back() == '(')stk.pop_back();
			else ok = false;
		}
		if(x == ']'){
			if(!stk.empty() && stk.back() == '[')stk.pop_back();
			else ok = false;
		}
	}
	ans.pop_back();
	for(int i = 0;i < ans.size();i++)cout << ans[i] << endl;
	return 0;
}
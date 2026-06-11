#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool check(string &s){
	char st[128],t;
	int sp=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='('){
			st[sp++]=s[i];
		}else if(s[i]=='['){
			st[sp++]=s[i];
		}else if(s[i]==')'){
			if(sp==0 || st[--sp]!='(')return false;
		}else if(s[i]==']'){
			if(sp==0 || st[--sp]!='[')return false;
		}
	}
	if(sp)return false;
	return true;
}
int main(){
	string s;
	while(1){
		getline(cin,s);
		if(s[0]=='.')break;
		cout<<(check(s)?"yes":"no")<<endl;
	}
	return 0;
}
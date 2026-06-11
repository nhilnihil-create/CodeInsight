#include<stack>
#include<cstdio>
#include<cstring>

using namespace std;

int main(){
	while(1){
		char s[128]; fgets(s,128,stdin);
		int n=strlen(s);
		if(s[n-1]=='\n') s[--n]='\0';
		if(strcmp(s,".")==0) break;

		bool ok=true;
		stack<char> St;
		for(int i=0;i<n;i++){
			if(s[i]=='(') St.push(s[i]);
			if(s[i]=='[') St.push(s[i]);
			if(s[i]==')') if(St.empty() || St.top()=='['){ ok=false; break; } else St.pop();
			if(s[i]==']') if(St.empty() || St.top()=='('){ ok=false; break; } else St.pop();
		}
		if(!St.empty()) ok=false;

		puts(ok?"yes":"no");
	}

	return 0;
}
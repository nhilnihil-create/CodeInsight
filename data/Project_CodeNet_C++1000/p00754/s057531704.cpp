#include <bits/stdc++.h>
#define REP(i,n,N) for(int i=(n);i<(int)(N);i++)
#define ck(n,a,b) (a)<=(n)&&(n)<=(b)
#define p(s) cout<<(s)<<endl
#define F first
#define S second
typedef long long ll;
using namespace std;

int main() {

	while(1){
		//int ind=0;
		char s[110]={};
		scanf("%c",&s[0]);
		if(s[0]=='\n') continue;
		if(s[0]=='.'){
			break;
		}
		int ind=0;
		while(s[ind]!='.'){
			ind++;
			scanf("%c",&s[ind]);
		}
		bool flag=true;
		stack<char> st;
		int i=0;
		while(s[i]!='.'){
			if(s[i]=='('||s[i]=='['){
				st.push(s[i]);
			}
			else if(s[i]==')'){
				if(!st.empty()&&st.top()=='('){
					st.pop();
				}else flag=false;
			}else if(s[i]==']'){
				if(!st.empty()&&st.top()=='['){
					st.pop();
				}else flag=false;
			}
			if(!flag) {
				break;
			}
			i++;
		}
		if(!st.empty()) flag=false;
		p(flag?"yes":"no");

	}

	return 0;
}
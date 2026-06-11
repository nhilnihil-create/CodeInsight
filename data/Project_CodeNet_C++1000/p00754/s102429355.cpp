#include <bits/stdc++.h>
#define REP(i,n,N) for(int i=n;i<N;i++)
#define p(S) cout<<S<<endl
using namespace std;

int main(){
	 while(1) {
		string c;
	    getline(cin, c);
	    if(c.size()==1 && c[0]=='.') break;
	    bool flag=true;
		stack<char> st;
		for(int i=0;c[i]!='.';i++){
			if((c[i]==')'||c[i]==']')&&st.empty()) {
				flag=false;
				break;
			}
			else if(c[i]=='('||c[i]=='[')			st.push(c[i]);
			else if(c[i]==')'&&st.top()=='(')	st.pop();
			else if(c[i]==']'&&st.top()=='[')	st.pop();
			else if(c[i]==']'||c[i]==')') {
				flag=false;
				break;
			}
		}

		if(flag&&st.empty()){
			p("yes");
		}else{
			p("no");
		}
	}

	return 0;
}
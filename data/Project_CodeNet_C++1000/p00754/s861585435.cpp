#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define REP(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;

int main(){ _;
  string s;
  while(getline(std::cin,s),s!="."){
    bool ok=true;
    stack<char> brackets;
    for(char c:s){
      if(c=='['){
	brackets.push('[');
      }else if(c==']'){
	if(!brackets.empty()&&brackets.top()=='[') brackets.pop();
	else{ok=false;break;}
      }
      else if(c=='('){
	brackets.push('(');
      }else if(c==')'){
	if(!brackets.empty()&&brackets.top()=='(') brackets.pop();
	else{ok=false;break;}
      }
    }
    cout<<(ok&&brackets.empty()?"yes":"no")<<endl;
  }
}
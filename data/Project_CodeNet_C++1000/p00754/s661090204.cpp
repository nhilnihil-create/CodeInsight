#include<iostream>
#include<stack>
#include<queue>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)

main(){
  string in;
  while(getline(cin,in) && in != "."){
    stack<char> S;
    bool fg=true;
    rep(i,in.size()){
      if (in[i] == '(')S.push(in[i]);
      if (in[i] == ')'){
	if (S.empty() || S.top() != '('){fg=false;break;}
	S.pop();
      }
      if (in[i] == '[')S.push(in[i]);
      if (in[i] == ']'){
	if (S.empty() || S.top() != '['){fg=false;break;}
	S.pop();
      }
    }
    if (S.empty() && fg)cout <<"yes" << endl;
    else  cout <<"no" << endl;
  }
}
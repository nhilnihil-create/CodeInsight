#include<iostream>
#include<stack>

using namespace std;

int check(char c){
  if(c == '[' || c == '(') return 2;
  if(c == ']' || c == ')') return 1;
  return 0;
}

int isOK(char c, char in){
  if(in == ']' && c == '[') return 1;
  if(in == ')' && c == '(') return 1;
  // cout << " " << c << " " << in << endl;
  return 0;
}

int main(){

  string in;
  while(getline(cin,in)){
    if(in == ".") break;
    stack<char> S;
    int status = 1;
    for(int i = 0; i < in.size(); i++){
      int j = check(in[i]);
      if(j == 2){
	S.push(in[i]);
	//	cout << " " << in[i] << endl;
      }
      if(j == 1) {
	if(S.size() == 0){
	  status = 0;
	  break;
	}
	if(!isOK(S.top(),in[i])){
	  status = 0;
	  break;
	}
	S.pop();
      }
    }
    if(status && S.size() == 0) cout << "yes" << endl;
    else cout << "no" << endl;
  }
  return 0;
}
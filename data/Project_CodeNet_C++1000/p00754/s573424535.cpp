#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
int main(){
  string str;
  string tmp;
  while(getline(cin, str) && str != "."){
    int p = 0, q = 0;
    bool flag = 1;
    tmp = "";
    
    for(int i = 0 ; i < str.size() ; i++){
      if(str[i] == '[' || str[i] == '(' || str[i] == ']' || str[i] == ')'){
	tmp += str[i];
      }
    }
    
    for(int i = 0 ; i < tmp.size() ; i++){
      if(tmp[i] == '(' && tmp[i+1] == ']') flag = 0;
      if(tmp[i] == '[' && tmp[i+1] == ')') flag = 0;
    }
    
    for(int i = 0 ; i < tmp.size() ; i++){
      //printf("p = %d, q = %d\n", p, q);
      if(p < 0 || q < 0){
	flag = 0;
	break;
      }
      if(tmp[i] == '(') p++;
      if(tmp[i] == '[') q++;
      if(tmp[i] == ')') p--;
      if(tmp[i] == ']') q--;
    }
    if(p != 0 || q != 0) flag = 0;

    
    stack<char> st;
    
    for(int i = 0 ; i < tmp.size() ; i++){
      if(tmp[i] == '(' || tmp[i] == '[') st.push(tmp[i]);
      else if(tmp[i] == ')'){
	if(st.empty() || st.top() != '('){ flag = 0; break;}
	else st.pop();
      }
      else if(tmp[i] == ']'){
	if(st.empty() || st.top() != '['){ flag = 0; break;}
	else st.pop();
      }
    }
    
    //cout << tmp << endl;
    //printf("p = %d, q = %d\n", p, q);*/
    if(flag) cout << "yes" << endl;
    else cout << "no" << endl;    
  }
  return 0;
}
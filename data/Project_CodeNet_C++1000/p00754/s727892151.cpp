#include<bits/stdc++.h>
using namespace std;

int main(){
  string str;
  while(getline(cin, str)){
    if(str.length() == 1 && str[0] == '.')break;

    stack<char> st;
    bool ok = true;
    for(int i = 0; i < str.length(); i++){
      if(st.empty()){
        if(str[i] == ']' || str[i] == ')'){
          ok = false;
          break;
        }
      }

      if(str[i] == '[' || str[i] == '('){
        st.push(str[i]);
      }else if(str[i] == ')' || str[i] == ']'){
        if((st.top() == '(' && str[i] == ')') || (st.top() == '[' && str[i] == ']')){
          st.pop();
        }else{
          ok = false;
          break;
        }
      }
    }
    cout << (st.empty() && ok ? "yes" : "no") << endl;
  }
}
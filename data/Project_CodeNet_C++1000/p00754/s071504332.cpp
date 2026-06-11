#include<bits/stdc++.h>
using namespace std;
int main(){
  string str;
  while(1){
    stack<int> s;
    bool ac = true;
    s.push('.');
    getline(cin,str);
    if(str == ".")break;
    for(int i=0;i<str.size();i++){
      if(str[i] == '[' || str[i] == ']' || str[i] == '(' || str[i] ==')'){
	if(str[i] == '[' || str[i] == '('){
	  s.push(str[i]);
	}
	if(str[i] == ']'){
	  if(s.top() == '['){
	    s.pop();
	  }else{
	    ac = false;
	  }
	}else if(str[i] == ')'){
	  if(s.top() == '('){
	    s.pop();
	  }else{
	    ac = false;
	  }
	}
      }
      if(!ac)break;
      
    }
    s.pop();
    if(!s.empty())ac = false;
    if(!ac)cout << "no" << endl;
    else cout << "yes" << endl;
  }
}
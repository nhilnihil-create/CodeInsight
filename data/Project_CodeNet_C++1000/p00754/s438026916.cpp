#include <stdio.h>
#include <stack>


int main(void){
  char c;
  bool ok;

  while(1){
    char s[101] = {0};
    ok = true;
    std::stack<char> st;
    for(int i=0; i<101; i++){
      scanf("%c", &c);
      if(c == '\n'){
	s[i] = '\0';
	break;
      }else{
	s[i] = c;
      }
    }
    
    if(s[0] == '.'){
      break;
    }
    
    for(int i=0; i<101; i++){
      if(s[i] == '.'){
	break;
      }
      if(s[i] == '(' || s[i] == '['){
	st.push(s[i]);
      }else if(s[i] == ')'){
	if(st.empty() || st.top()!='('){
	  ok = false;
	  break;
	}else{
	  st.pop();
	}
      }else if(s[i] == ']'){
	if(st.empty() || st.top() != '['){
	  ok = false;
	  break;
	}else{
	  st.pop();
	}
      }
    }
    
    if(!st.empty()){
      ok = false;
    }
    
    if(ok){
      printf("yes\n");
    }else{
      printf("no\n");
    }
    
  }
  return 0;
}
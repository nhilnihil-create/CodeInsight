#include <stdio.h>
int main(){
  int i,ib;
  char a,s[100];
  while(1){
    i=0;
    scanf("%c",&a);
    if(a=='.')break;
    else if(a=='('){
      s[i]='(';
      i++;
    }else if(a==')'){
      s[i]=')';
      i++;
    }else if(a=='['){
      s[i]='[';
      i++;
    }else if(a==']'){
      s[i]=']';
      i++;
    }
    while(1){
      scanf("%c",&a);
      if(a=='.'){
	if(i==0){
	  printf("yes\n");
	  break;
	}else {
	  printf("no\n");
	  break;
	}
      }else if(a=='('){
	s[i]='(';
	i++;
      }else if(a==')'){
	if(s[i-1]=='(')i--;
	else {
	  s[i]=')';
	  i++;
	}
      }else if(a=='['){
	s[i]='[';
	i++;
      }else if(a==']'){
	if(s[i-1]=='[')i--;
	else {
	  s[i]=']';
	  i++;
	}
      }
    }
    scanf("%c",&a);
  }
  return 0;
}
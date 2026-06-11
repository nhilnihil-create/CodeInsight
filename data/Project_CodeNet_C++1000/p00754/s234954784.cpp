#include<stdio.h>
#include<list>

int main(){
  using namespace std;
  int i;
  char str[102];
  list<char> ls;
  do{
    fgets(str,102,stdin);
    if(str[0]=='.') break;
    ls.clear();
    for(i=0;str[i]!='.';i++){
      switch(str[i]){
      case '(':
	ls.push_front('(');
	break;
      case ')':
	if(ls.front()!='('){
	  printf("no\n");
	  goto end;
	}
	ls.pop_front();
	break;
      case '[':
	ls.push_front('[');
	break;
      case ']':
	if(ls.front()!='['){
	  printf("no\n");
	  goto end;
	}
	ls.pop_front();
	break;
      }
    }
    if(ls.empty()) printf("yes\n");
    else printf("no\n");
  end:;
  }while(1);
  return 0;
}
  
    
#include<vector>
#include<list>
#include<algorithm>
#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
  int h,i;
  int ln;
  char c[256];
  string s;
  for(;;){
    fgets(c,256,stdin);
    s=c;
    ln=s.length();
    if(ln==2)
      break;
    for(i=0;i<ln;i++){
      if(s[i]!='('&&s[i]!=')'&&s[i]!='['&&s[i]!=']'){
	s.erase(i,1);
	ln--;
	i--;
      }
    }
    do{
      h=0;
      for(i=1;i<ln;i++){
	if(0){
	}else if(s[i-1]=='('&&s[i]==')'){
	  s.erase(i-1,2);
	  ln-=2;
	  h=1;
	  break;
	}else if(s[i-1]=='['&&s[i]==']'){
	  s.erase(i-1,2);
	  ln-=2;
	  h=1;
	  break;
	}
      }
    }while(h);
    if(ln)
      cout<<"no"<<endl;
    else
      cout<<"yes"<<endl;
  }
  return 0;
}
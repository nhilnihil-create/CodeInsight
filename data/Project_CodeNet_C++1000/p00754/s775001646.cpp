#include<cstdio>
#include<vector>
using namespace std;
int main(){
  while(1){
    char t;
    vector<int> s;
    int b=0,f=0;
    while(1){
      scanf("%c",&t);
      if(t=='.')break;
      b=1;
      if((t!='('&&t!=')'&&t!='['&&t!=']')||f==1)continue;
      else if(t=='(')s.push_back(1);
      else if(t=='[')s.push_back(2);
      else if(!s.empty()){
	if(s.back()==1&&t==')')s.pop_back();
	else if(s.back()==2&&t==']')s.pop_back();
	else f=1;
      }
      else if(t==']'||t==')')f=1;
    }scanf("%c",&t);
    if(b==0)break;
    else if(f==0&&s.empty())printf("yes\n");
    else printf("no\n");
  }
  return 0;
}
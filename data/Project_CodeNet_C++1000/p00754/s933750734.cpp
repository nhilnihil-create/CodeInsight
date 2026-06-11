#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
  string s;
  while(1){
    getline(cin,s);
    if(s.size()==1&&s[0]=='.')break;
    string tmp;
    bool ok=true;
    for(int i=0;i<s.size();i++){
      if(s[i]=='(')tmp.push_back('(');
      if(s[i]=='[')tmp.push_back('[');

      if(s[i]==')'&&tmp[tmp.size()-1]=='('){
	tmp.pop_back();
      }else if(s[i]==')'&&(tmp[tmp.size()-1]=='['||tmp.size()==0)){
	ok=false;
	break;
      }

      if(s[i]==']'&&tmp[tmp.size()-1]=='['){
	tmp.pop_back();
      }else if(s[i]==']'&&(tmp[tmp.size()-1]=='('||tmp.size()==0)){
	ok=false;
	break;
      }
    }
    if(ok&&tmp.size()==0)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    
  }
  return 0;
}
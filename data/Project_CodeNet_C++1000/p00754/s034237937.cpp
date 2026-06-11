#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(){
  string a;
  while(getline(cin,a)){
    if(a[0]=='.')break;
    stack<char> b;
    int c=0;
    for(int i=0;i<a.size();i++){
      if(a[i]=='['||a[i]=='(')b.push(a[i]);
      if(a[i]==']'||a[i]==')'){
        if(b.empty())c++;
        else if((b.top()=='['&&a[i]==']')||(b.top()=='('&&a[i]==')'))b.pop();
        else c++;
      }
    }
    if(c==0&&b.empty())cout<<"yes"<<endl;
    else cout<<"no"<<endl;
  }
  return 0;
}
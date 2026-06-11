#include<bits/stdc++.h>
using namespace std;
main(){
  stack<int> num;
  char now[15];
  long long ans=0;
  while(cin>>now){
    if(now[0]=='+'){
      int a,b;
      a=num.top();num.pop();
      b=num.top();num.pop();
      num.push(a+b);
    }
    else if(now[0]=='-'){
      int a,b;
      a=num.top();num.pop();
      b=num.top();num.pop();
      num.push(b-a);
    }
    else if(now[0]=='*'){
      int a,b;
      a=num.top();num.pop();
      b=num.top();num.pop();
      num.push(a*b);
    }
    else if(now[0]=='/'){
      int a,b;
      a=num.top();num.pop();
      b=num.top();num.pop();
      num.push(b/a);
    }
    else{
      num.push(atoi(now));
    }
  }
  cout<<num.top()<<endl;
  num.pop();
  return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define rep(i,x,y) for(int (i)=(x);(i)<(y);(i)++)

int main()
{
  while(true){

    char s;

    stack<char> st;
    bool endflag=true;
    bool flag=true;

    while((s=getchar())!='.'){
      endflag=false;
      if(s=='['){
        st.push('[');
      }
      if(s=='('){
        st.push('(');
      }
      if(s==']'){
        if(st.empty()==true){
          flag=false;
          break;
        }else{
          if(st.top()=='['){
            st.pop();
          }else{
            flag=false;
            break;
          }
        }
      }
      if(s==')'){
        if(st.empty()==true){
          flag=false;
          break;
        }else{
          if(st.top()=='('){
            st.pop();
          }else{
            flag=false;
            break;
          }
        }
      }
    }

    if(endflag==true){
      break;
    }
    if(st.empty()==false){
      flag=false;
    }

    if(flag==true){
      cout<<"yes"<<endl;
    }else{
      cout<<"no"<<endl;
    }
    while(getchar()!='\n');
  }

  return 0;
}
#include<iostream>
#include<stack>
#include<cstdlib>
using namespace std;
typedef pair<int,char> P;


int main(){
  string s;
  stack<P> st;
  int cc,lc;
  while(getline(cin,s) && s != "."){
    cc = 0;
    lc = 0;
    for(int i=0;i<s.length();i++)
      {
	if(s[i] == '(')
	  {
	    st.push(P('c',cc));
	    cc++;
	  }
	else if(s[i] == '[')
	  {
	    st.push(P('l',lc));
	    lc++;
	  }
	else if(s[i] == ')')
	  {
	    if(st.empty()){
	      st.push(P('v',-1));
	      break;
	    }
	    if(st.top().first == 'c')
	      {
		cc--;
		st.pop();
	      }
	    else
	      {
		break;
	      }
	  }
	else if(s[i] == ']')
	  {
	    if(st.empty()){
	      st.push(P('t',-2));
	      break;
	    }
	    if(st.top().first == 'l')
	      {
		lc--;
		st.pop();
	      }
	    else 
	      {
		break;
	      }
	  }

      }   

    if(st.empty())
      {
	cout << "yes" << endl;
      }
    else
      {
	cout << "no" << endl;
	while(st.size())
	  {
	    st.pop();
	  }
      }
  

  }



}
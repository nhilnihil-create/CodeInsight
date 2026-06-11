#include <iostream>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int,int> > vp;

int main()
{
  while(1)
    {
      string s;
      getline(cin,s);
      if(s==".") break;
      stack<char> pot;
      int sql=0,sqr=0,cil=0,cir=0;
      bool miss=false;
      bool psql=false,pcil=false;
      for(int i=0;i<s.size();i++)
	{
	  if(s[i]=='(')
	    {
	      cil++;
	      pot.push('(');
	    }
	  else if(s[i]==')') 
	    {		  
	      cir++;
	      if(pot.empty() || pot.top()!='(')
		{
		  cout << "no" << endl;
		  miss=true;
		  break;
		}
	      pot.pop();
	    }
	  else if(s[i]=='[') 
	    {
	      sql++;
	      pot.push('[');
	    }
	  else if(s[i]==']') 
	    {
	      sqr++;
	      if(pot.empty() || pot.top()!='[')
		{
		  cout << "no" << endl;
		  miss=true;
		  break;
		}
	      pot.pop();
	    }
	  if(sqr>sql || cir>cil)
	    {
	      cout << "no" << endl;
	      miss=true;
	      break;
	    }
	}
      if(!miss)
	{
	  if(sql==sqr && cil==cir)
	    {
	      cout << "yes" << endl;
	    }
	  else
	    {
	      cout << "no" << endl;
	    }
	}
    }
  return 0;
}
      


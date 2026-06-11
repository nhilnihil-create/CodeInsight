#include<iostream>
#include<string.h>
#include<string>
#include<cstdio>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<utility>
#include<set>
#define ll long long int
#define ld long double
#define INF 1000000000
#define EPS 0.0000000001
#define rep(i,n) for(i=0;i<n;i++)
using namespace std;
typedef pair<int, int> pii;

int main()
{
  while(1){
    stack<int> sta;//[]:1 ():2 
    bool ans=true;
    string c;
    getline(cin,c);
    if(c[0]=='.')break;
    else if(c[0]=='[')sta.push(1);
    else if(c[0]=='(')sta.push(2);
    else if(c[0]==']' || c[0]==')')ans=false;
    int i=0;
    while(ans){
      i++;
      // printf("c='%c'\n",c[i]);
      if(c[i]=='[')sta.push(1);
      else if(c[i]=='(')sta.push(2);
      else if(c[i]==']')
	if(sta.size() && sta.top()==1)sta.pop();
	else{
	  ans=false;
	  break;
	}
      else if(c[i]==')')
	if(sta.size() && sta.top()==2)sta.pop();
	else{
	  ans=false;
	  break;
	}
      else if(c[i]=='.')break;
    }
    if(sta.size()==0 && ans)cout<<"yes"<<endl;
    else{
      cout<<"no"<<endl;
    }
  }


}
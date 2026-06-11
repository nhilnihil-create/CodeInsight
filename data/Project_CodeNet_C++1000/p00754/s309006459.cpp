#include <bits/stdc++.h>
#define REP(a,b,c) for(int a=b; a<(int)c; a++)
#define REPE(a,b,c) for(int a=b; a<=(int)c; a++)
#define REPD(a,b,c) for(int a=b; a>=(int)c; a--)
#define rep(a,b) REP(a,0,b)
#define repd(a,b) REPD(a,b,0)
typedef long long int ll;
using namespace std;
string str;
int pos;
bool DFS(char c){
  // cout << endl << endl;
  //cout << pos << " " << c << endl;
  while(true){
    if(pos >= str.size()){
      return c==' ';
    }
    char ch = str[pos];
    //cout << ch;
    switch(ch){
    case  '[':
    case  '(':
      pos++;
      if(!DFS(ch)) return false;
      break;
    case  ']':
      // cout << endl;
      //cout <<pos<<":"<< c << ch << endl;
      return c=='[';
      break;
    case  ')':
      //cout << endl;
      //cout <<pos<<":"<< c << ch << endl;
      return c=='(';
      break;
    }
    pos++;
  }
  return true;
}

int main(){
  while(true){
    getline(cin,str);
    if(str == ".") break;
    pos = 0;
    if(DFS(' ')){
      cout << "yes" << endl;
    }else{
      cout << "no" << endl;
    }
  }
  return 0;
}
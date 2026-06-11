#include<iostream>
#include<string>
using namespace std;
int main()
{
  string S,s,es;
  s = 's';
  es = "es";
  int slong;
  cin >> S;
  
  slong = S.size();
  if(S[slong-1]=='s'){
    S = S + es;
  }else{
    S = S + s;
  }
  
  cout <<S;
}
  
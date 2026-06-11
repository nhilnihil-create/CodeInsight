#include<bits/stdc++.h>
using namespace std;
int main(){
  string s,t,u;
  int a,b;
  
  cin >> s >> t >> a >> b >> u;
  
  if(u==s)
    a = a-1; 
  else
    b = b-1;
  
  cout << a << " " <<  b ;
  
}
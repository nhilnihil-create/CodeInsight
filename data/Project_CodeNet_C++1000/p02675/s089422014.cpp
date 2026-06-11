#include <bits/stdc++.h>
using namespace std;

int main() {
  string N;
  cin >>N;
  int X = N.size()-1;
  
  if(N.at(X)=='3')
  cout<<"bon";
  
  else if(N.at(X)=='0'||N.at(X)=='1'||N.at(X)=='6'||N.at(X)=='8')
  cout<<"pon";
  
  else
  cout<<"hon";
}
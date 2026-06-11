#include<bits/stdc++.h>
using namespace std;

int main(){
  char a,b;
  cin >> a >> b;
  string sa,sb;
  for(int i=0;i<a-48;i++)
    sa+=b;
  for(int i=0;i<b-48;i++)
    sb+=a;
  cout << (sa>sb?sb:sa) << endl;
  return 0;
}
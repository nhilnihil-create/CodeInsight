#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int n=(1+s.size())/2;
  if(s.substr(0,n-1)==s.substr(n,s.size()))cout << "Yes" << endl;
  else cout << "No" << endl;
}
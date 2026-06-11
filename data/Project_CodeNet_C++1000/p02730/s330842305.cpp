#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef long long ld;


bool palin(string s){
  string tmp = s;
  reverse(tmp.begin(), tmp.end());
  return s == tmp;
}


int main() {
  string s;
  cin >> s;
  int n = s.length();
  
  if(!palin(s)) cout<<"No"<<endl;
  else if(palin(s.substr(0,n/2)) && palin(s.substr(n/2+1))) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  
}
#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;string s;
  cin >> n >> s;
  bool b=1;
  if(n%2==1) b=0;
  else{
    string a=s.substr(0,n/2),c=s.substr(n/2,n/2);
    if(a!=c) b=0;
  }
  if(b) cout << "Yes" << endl;
  else cout << "No" << endl;
}

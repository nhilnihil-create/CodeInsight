#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  bool flag=true;
  int k=s.size();
  for (int i=0; i<k; i++){
    if (s.at(i)!=t.at(i)){
      flag=false;
      break;
    }
  }
  if(flag)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
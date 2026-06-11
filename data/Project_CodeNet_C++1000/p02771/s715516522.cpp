#include <bits/stdc++.h>
using namespace std;


int main() {
  int a,b,c;
  
  cin >> a >> b >> c;
  
  set<int> val{a,b,c};
  
  if(val.size() == 2)
    cout << "Yes";
  else
    cout << "No";
  
  
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >>s >>t;

 for(int i = 0; i<s.length(); i++){
    if(s.at(i)!=t.at(i)){
    cout <<"No";
   return 0;
    }
 }
  cout<< "Yes";
 }

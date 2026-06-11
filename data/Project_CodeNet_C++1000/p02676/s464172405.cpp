#include <bits/stdc++.h>
using namespace std;
int main(){
  int k; cin >> k;
  string s; cin >> s;
  if(s.size()<=k)
    cout << s;
  else{
    for(int i = 0; i < k; i++)
      cout << s.at(i);
    cout << "...";
  }
}
#include <bits/stdc++.h>
using namespace std;
int main(){
  int k;	cin >> k;
  string s;	cin >> s;
  if(s.size()<=k){
    cout << s;
    return 0;
  }
  cout << s.substr(0,k)+"...";
}
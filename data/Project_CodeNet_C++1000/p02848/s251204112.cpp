#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  int n;
  cin >> n >> s;
  for(int i = 0; i < s.size(); i++){
    s[i] += n;
    if(s[i] > 'Z') s[i] -= 'Z' - 'A' + 1;
  }
  cout << s << endl;
}
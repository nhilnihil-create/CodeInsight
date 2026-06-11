#include <bits/stdc++.h>
using namespace std;
int main(){
  int k;
  string s;
  cin >> k >> s;
  for(int i=0; i<min(k, (int)s.size()); i++){
    cout << s[i];
  }
  cout << (k < s.size() ? "..." : "") << endl;
}
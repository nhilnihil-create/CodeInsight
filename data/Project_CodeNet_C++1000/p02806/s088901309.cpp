#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, a, b;
  cin >> n;
  vector<string> s(n);
  vector<int> t(n);
  for(int i = 0; i < n; i++){
    cin >> s[i] >> t[i];
  }
  string x;
  cin >> x;
  for(int i = 0; i < n; i++){
    if(x == s[i])
      a = i;
  }
  b = 0;
  for(int i = a + 1; i < n; i++)
    b += t[i];
  cout << b << endl;
}

#include<bits/stdc++.h>

using namespace std;

int main(void){
  string s;
  long long a;
  cin >> s;
  for(int i = 0; i < s.length(); i++) a += (s[i] - '0');
  if(a % 9 == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

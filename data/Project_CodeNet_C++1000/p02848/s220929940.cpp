#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  
  int len = s.size();
  for(int i = 0; i < len; i++){
    int x = s[i] - 'A';
    x = (x+n)%26;
    s[i] = x + 'A';
  }
  

  cout << s << endl;
}
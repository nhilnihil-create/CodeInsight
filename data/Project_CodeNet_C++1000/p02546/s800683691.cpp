#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  string str;
  int i = 0;
  
  cin >> str;
  i = str.size() - 1;
  if (str[i] == 's')
    cout << str << 'e' << 's' <<endl;
  else
    cout << str << 's' << endl;
  return 0;
}
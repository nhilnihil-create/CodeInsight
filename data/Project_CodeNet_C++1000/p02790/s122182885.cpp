#include <iostream>
using namespace std;

int main()
{
  int a, b;
  cin >> a >> b;
  int cnt = a >= b ? a : b;
  string s = to_string(a >= b ? b : a);
  for(int i=0; i<cnt; i++)
    cout << s;
  
  cout << endl;
  return 0;
}
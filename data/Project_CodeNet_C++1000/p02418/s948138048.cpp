#include <iostream>
#include <string>

using namespace std;

int main()
{
  string a, b, c;
  string::size_type d;
  cin >> a >> c;
  b = a + a;
  d = b.find(c);
  if(d == string::npos) cout << "No" << endl;
  else cout << "Yes" << endl;
}
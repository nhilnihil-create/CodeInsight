#include <iostream>
#define INF 1000000000000000000LL
using namespace std;
using ll = long long;

int main()
{
  string t;
  cin >> t;
  while(t.find("?") != string::npos)
    t.replace(t.find("?"),1,"D");

  cout << t << endl;
  return 0;
}
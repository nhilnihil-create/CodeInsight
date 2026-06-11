#include <iostream>
#include <string>

using namespace std;

int main()
{
  int n;
  cin >> n;
  string s;

  cin >> s;

  int cnt = 0;

  std::string::size_type pos = s.find("ABC");
  while (pos != std::string::npos)

  {
    cnt++;
    pos = s.find("ABC", pos + 3);
  }

  cout << cnt << endl;
  return 0;
}
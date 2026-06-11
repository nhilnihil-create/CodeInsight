
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int a;
  cin >> a;
  string str;
  map<string, int> string_map;
  for(int i = 0; i < a; i++)
  {
    cin >> str;
    string_map[str]++;
  }
  cout << string_map.size() << endl;
  return 0;
}

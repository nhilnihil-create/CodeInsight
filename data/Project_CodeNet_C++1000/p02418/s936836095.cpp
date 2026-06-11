/*
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_8_D
 */
#include <iostream>
#include <string>

using namespace std;

int
main()
{
  ios::sync_with_stdio(false);

  string s, p;
  getline(cin, s);
  s += s;
  getline(cin, p);

  size_t found = s.find(p);
  cout << (found == string::npos ? "No" : "Yes") << endl;

  return 0;
}
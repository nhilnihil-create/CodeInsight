#include <iostream>
#include <string>
using namespace std;

int main()
{
  string S, s, r;
  int N;
  bool strong = true;
  cin >> S;
  r = S;
  N = S.length();
  reverse(r.begin(), r.end());

  if (S != r)
    strong = false;

  s = S.substr(0, (N - 1) / 2);
  r = s;
  reverse(r.begin(), r.end());

  if (s != r)
    strong = false;

  s = S.substr((N + 3) / 2 - 1, N - (N + 3) / 2 + 1);
  r = s;
  reverse(r.begin(), r.end());

  if (s != r)
    strong = false;

  if (strong)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}

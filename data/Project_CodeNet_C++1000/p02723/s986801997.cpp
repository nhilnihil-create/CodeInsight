#include <iostream>
#include <vector>

using namespace std;

void abc_160a();

int main()
{
  abc_160a();
}

void abc_160a()
{
  string S;
  cin >> S;

  if (S[2] == S[3] && S[4] == S[5]) cout << "Yes\n";
  else cout << "No\n";
}

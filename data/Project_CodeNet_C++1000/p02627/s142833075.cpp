#include <iostream>
#include <vector>

using namespace std;

void abc_170a();

void abc_171a();

int main()
{
  //abc_170a();
  abc_171a();

}

void abc_170a()
{
  vector<int> x(5);
  for (int i = 0; i < 5; ++i) cin >> x[i];

  for (int i = 0; i < 5; ++i)
  {
    if (x[i] == 0)
    {
      cout << i + 1 << "\n";
      return;
    }
  }
}


void abc_171a()
{
  char c;
  cin >> c;

  if (c == tolower(c)) cout << "a\n";
  else cout << "A\n";
}

#include <iostream>
#include <vector>

using namespace std;

void abc_150a();

void abc_151a();

int main()
{
  //abc_150a();
  abc_151a();

}

void abc_150a()
{
  int K, X;
  cin >> K >> X;

  if (500 * K >= X) cout << "Yes\n";
  else cout << "No\n";
}

void abc_151a()
{
  char C;
  cin >> C;

  cout << (char)((int)C + 1) << "\n";
}

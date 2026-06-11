#include <iostream>
#include <vector>

using namespace std;

void abc_150a();

int main()
{
  abc_150a();

}

void abc_150a()
{
  int K, X;
  cin >> K >> X;

  if (500 * K >= X) cout << "Yes\n";
  else cout << "No\n";
}

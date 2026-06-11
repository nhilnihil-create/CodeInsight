#include <iostream>
using namespace std;

int main()
{
  int H, N, dmg, sum = 0;

  cin >> H >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> dmg;
    sum += dmg;
  }

  cout << (sum >= H ? "Yes" : "No") << endl;
}

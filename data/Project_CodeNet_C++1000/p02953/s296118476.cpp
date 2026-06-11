#include <iostream>
#include <string>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  int N;
  cin >> N;

  vector<int> H(N);
  rep(i, N) cin >> H[i];

  bool no = false;
  for (int i = N - 1; i > 0; i--)
  {
    if (H[i] < H[i - 1])
    {
      H[i - 1]--;
    }
    if (H[i] < H[i - 1])
    {
      no = true;
      break;
    }
  }

  if (no)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;

  return 0;
}

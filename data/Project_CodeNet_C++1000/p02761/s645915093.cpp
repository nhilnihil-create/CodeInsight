#include <iostream>
#include <vector>
using namespace std;

int ipow(int base, int k)
{
  int r = 1;
  while(k--) r *= base;
  return r;
}

int main()
{
  int N, M;
  cin >> N >> M;
  vector<int> s(M), c(M);
  for (int i = 0; i < M; ++i)
    cin >> s[i] >> c[i];
  
  int first = (N == 1) ? 0 : ipow(10, N-1);

  int last = ipow(10, N);
  
  int ans = -1;
  for (int num = first; num < last; ++num)
  {
    string num_str = to_string(num);
    bool ok = true;
    for (int m = 0; ok && m < M; ++m)
      if (num_str[s[m]-1] - '0' != c[m])
        ok = false;

    if (ok)
    {
      ans = num;
      break;
    }
  }
  cout << ans << endl;
}

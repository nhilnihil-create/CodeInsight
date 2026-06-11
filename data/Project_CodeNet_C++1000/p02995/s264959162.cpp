#include <iostream>
#include <string>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

long long gcd(long long a, long long b)
{
  if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}

long long lcm(long long a, long long b)
{
  return a * b / gcd(a, b);
}

int main()
{
  long long A, B;
  long long C, D;
  cin >> A >> B >> C >> D;

  long long count = 0;

  long long div_c = B / C - (A - 1) / C;
  long long div_d = B / D - (A - 1) / D;
  long long lcm_ = lcm(C, D);
  long long div_c_d = B / lcm_ - (A - 1) / lcm_;

  cout << B - A + 1 - div_c - div_d + div_c_d << endl;

  return 0;
}

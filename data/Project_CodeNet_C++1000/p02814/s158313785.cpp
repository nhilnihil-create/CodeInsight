#include <iostream>
#include <vector>

unsigned long long gcd(unsigned long long a, unsigned long long b);
unsigned long long lcm(unsigned long long a, unsigned long long b);

int main()
{
  int N, M;
  std::cin >> N >> M;
  std::vector<unsigned long long> a(N);
  unsigned long long half_LCM = 1;
  bool exist = true;
  for (int i = 0; i < N; i++)
  {
    std::cin >> a.at(i);
    a.at(i) /= 2;
    half_LCM = lcm(half_LCM, a.at(i));
    if ((half_LCM / a.at(i)) % 2 == 0)
    {
      exist = false;
      break;
    }
    if (half_LCM > M)
    {
      exist = false;
      break;
    }
  }
  if (exist)
  {
    std::cout << (M - half_LCM) / (2*half_LCM) + 1 << std::endl;
  }
  else std::cout << 0 << std::endl;
}

/* ++++++++++ function ++++++++++ */
unsigned long long gcd(unsigned long long a, unsigned long long b)
{
  if(a < b) return gcd(b, a);
  unsigned long long r;
  while ((r=a%b))
  {
    a = b;
    b = r;
  }
  return b;
}

unsigned long long lcm(unsigned long long a, unsigned long long b)
{
  unsigned long long gcd_ab = gcd(a, b);
  return a/gcd_ab * b;
}

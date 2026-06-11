#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

namespace
{

}

namespace ABC169
{

  class D
  {
  public:
    D() = default;
    ~D() = default;

    bool IsPrime(long long num)
    {
      if (num < 2) return false;
      if (num == 2) return true;

      for (long long i = 2; i*i <= num; ++i)
      {
        if (num%i == 0)
        {
          return (num/i) == 1;
        }
      }

      return true;
    }

    void Run()
    {
      long long N;
      std::cin >> N;

      std::vector<long long> yakusu = {};
      {
        auto v = N;
        for (long long i = 2; i*i <= v; ++i)
        {
          if (!IsPrime(i)) continue;

          while (v%i == 0)
          {
            yakusu.push_back(i);
            v /= i;
          }
        }
        if (IsPrime(v)) { yakusu.push_back(v); }
      }

      int p_count = 0;
      int use_count = 0;
      int max_count = 0;
      int before_v = 0;
      for (auto v : yakusu)
      {
        if (v != before_v)
        {
          use_count = 0;
          max_count = 0;
        }
        before_v = v;
        use_count++;

        if (use_count > max_count)
        {
          p_count++;
          use_count = 0;
          max_count++;
        }
      }

      std::cout <<  p_count  << std::endl;
    }
  };

}

int main()
{

  ABC169::D prob;
  prob.Run();

  return 0;
}


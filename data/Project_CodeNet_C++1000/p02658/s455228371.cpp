#include <iostream>
#include <vector>
#include <algorithm>

namespace ABC169
{

  class B
  {
  public:
    B() = default;
    ~B() = default;

    void Run()
    {
      int N;
      long long A[100001];
      std::cin >> N;

      bool over = false;
      long long accm = 1;
      for (int i = 0; i < N; ++i)
      {
        std::cin >> A[i];

        if (A[i] == 0)
        {
          over = false;
          accm = 0;
          break;
        }
        if (over) continue;

        int ten_count = 0;
        long long v = A[i];
        while (v >= 10)
        {
          v /= 10;
          ten_count++;
        }

        int accm_ten_count = 0;
        long long accm_v = accm;
        while (accm_v >= 10)
        {
          accm_v /= 10;
          accm_ten_count++;
        }

        if (ten_count + accm_ten_count > 18)
        {
          over = true;
        }
        else if (ten_count + accm_ten_count == 18)
        {
          auto v1 = accm;
          auto v2 = A[i];
          if (v1*v2 != 1000000000000000000)
          {
            over = true;
          }
        }

        accm *= A[i];
      }

      over |= (accm > 1000000000000000000);

      std::cout << (over ? -1 : accm) << std::endl;
    }
  };

}
int main()
{

  ABC169::B prob;
  prob.Run();

  return 0;
}


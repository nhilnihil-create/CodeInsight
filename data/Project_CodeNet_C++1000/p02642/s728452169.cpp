#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

namespace
{
  static std::array<int, 1000001> ng_nums = {};
  static std::array<int, 1000001> num_count = {};

}

namespace ABC170
{

  class D
  {
  public:
    D() = default;
    ~D() = default;


    void Run()
    {
      int N;
      std::cin >> N;

      std::vector<int>A = {};
      for (int i = 0; i < N; ++i)
      {
        int v;
        std::cin >> v;
        A.push_back(v);
      }
      std::sort(A.begin(), A.end());

      for(auto v : A)
      {
        if (ng_nums[v] == 0)
        {
          if (num_count[v] == 1) { ng_nums[v] = 1; }

          for (int i = v + v; i <= 1000000; i += v)
          {
//            if (ng_nums[i] == 1) { break; }
            ng_nums[i] = 1;
          }
        }

        num_count[v] = 1;
      }

      int count = 0;
      for (int i = 0; i < N; ++i)
      {
        if (ng_nums[A[i]] == 0) count++;
      }

      std::cout << count << std::endl;
    }
  };

}
int main()
{

  ABC170::D prob;
  prob.Run();

  return 0;
}


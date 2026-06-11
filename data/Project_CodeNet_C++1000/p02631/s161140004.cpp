#include <iostream>
#include <string>

namespace ABC171
{
  class E
  {
  public:
    E() = default;
    ~E() = default;


    void Run()
    {
      int N = {};
      std::cin >> N;

      static int X[200001] = {};
      static int A[200001] = {};
      int sum = {};
      for (int i = 0; i < N; ++i)
      {
        std::cin >> A[i];
        sum ^= A[i];
      }

      for (int i = 0; i < N; ++i)
      {
        int answer = sum ^ A[i];
        std::cout << answer << std::endl;
      }

    }
  };


}

int main()
{

  ABC171::E prob;
  prob.Run();

  return 0;
}


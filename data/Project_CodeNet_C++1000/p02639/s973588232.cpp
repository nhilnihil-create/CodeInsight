#include <iostream>

namespace ABC170
{

  class A
  {
  public:
    A() = default;
    ~A() = default;


    void Run()
    {

      int A = 0;
      for (int i = 1; i <= 5; ++i)
      {
        int N;
        std::cin >> N;
        if (N == 0) A = i;
      }

      std::cout << A << std::endl;
    }
  };

}

int main()
{

  ABC170::A prob;
  prob.Run();

  return 0;
}

#include <iostream>
#include <array>

namespace ABC170
{

  class C
  {
  public:
    C() = default;
    ~C() = default;


    void Run()
    {
      int X, N;
      std::array<int, 301> p = {};
      std::cin >> X;
      std::cin >> N;
      for (int i = 0; i < N; ++i)
      {
        int v;
        std::cin >> v;
        p[v] = 1;
      }

      auto answer = 0;
      for (int i = 0; i <= N; ++i)
      {
        if (p[X - i] == 0) { answer = X - i; break; }

        if (p[X + i] == 0) { answer = X + i; break; }
      }


      std::cout << answer << std::endl;
    }
  };

}

int main()
{

  ABC170::C prob;
  prob.Run();

  return 0;
}

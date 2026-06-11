#include <iostream>
#include <string>

namespace ABC170
{

  class B
  {
  public:
    B() = default;
    ~B() = default;


    void Run()
    {
      int X, Y;
      std::cin >> X;
      std::cin >> Y;

      int min = X * 2;
      int max = X * 4;

      bool yes = (min <= Y) && (Y <= max) && (Y % 2 == 0);

      std::cout << (yes ? "Yes" : "No") << std::endl;
    }
  };

}
int main()
{

  ABC170::B prob;
  prob.Run();

  int a;
  std::cin >> a;
  return 0;
}


#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>

namespace ABC168
{

  class A
  {
  public:
    A() = default;
    ~A() = default;


    void Run()
    {

      int A = 0;
      std::cin >> A;

      auto ichi = A % 10;

      std::string yomi = "";

      switch (ichi)
      {
      case 3:
        yomi = "bon";
        break;
      case 0:
      case 1:
      case 8:
      case 6:
        yomi = "pon";
        break;
      case 2:
      case 4:
      case 5:
      case 7:
      default: // 9
        yomi = "hon";
      }

      std::cout << yomi << std::endl;
    }
  };

}
int main()
{

  ABC168::A prob;
  prob.Run();

  return 0;
}


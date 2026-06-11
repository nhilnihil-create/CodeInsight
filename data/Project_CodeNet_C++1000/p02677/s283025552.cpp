#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <math.h>
#include <iomanip>

namespace ABC168
{

  class C
  {
  public:
    C() = default;
    ~C() = default;


    void Run()
    {

      int A = 0; // hour
      int B = 0; // min
      int H = 0;
      int M = 0;
      std::cin >> A;
      std::cin >> B;
      std::cin >> H;
      std::cin >> M;

      double rad_A = (90 - (double)(H * 30) - ((double)M*30.0f / 60.0f))/180.0f * M_PI ;
      double rad_B = (double)(90 - M * 6) / 180.0f * M_PI;

      auto A_x = A * sin(rad_A);
      auto A_y = A * cos(rad_A);
      auto B_x = B * sin(rad_B);
      auto B_y = B * cos(rad_B);

      double answer = sqrt((A_x - B_x)*(A_x - B_x) + (A_y - B_y)*(A_y - B_y));

      std::cout << std::fixed << std::setprecision(15) << answer << std::endl;
    }
  };

}
int main()
{

  ABC168::C prob;
  prob.Run();

  return 0;
}


#include <iostream>

int main()
{
  int N;
  std::cin >> N;

  // ones place
  int a = N % 10;
  std::string out = "hon";
  switch (a) {
    case(0):
    case(1):
    case(6):
    case(8): {
      out = "pon";
      break;
    }
    case(3): {
      out = "bon";
      break;
    }
    default: {
      break;
    }
  }

  std::cout << out << std::endl;

  return 0;
}

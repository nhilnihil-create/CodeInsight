#include <iostream>

int main() {
  int coin, point = 0;
  std::cin >> coin;
  while (true) {
    if (coin >= 500) {
      coin -= 500;
      point += 1000;
    }
    else {
      break;
    }
  }
  while (true) { 
    if (coin >= 5) {
    coin -= 5;
    point += 5;
    }
    else {
      break;
    }
  }
  std::cout << point;
}
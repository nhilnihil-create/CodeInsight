#include <bits/stdc++.h>

class Dice {
public:
  int u;
  int r;
  int l;
  int d;
  int b;
  int f;
  void S(void) {
    int temp;
    temp = u; u = b; b = d; d = f; f = temp;
  }
  void N(void) {
    int temp;
    temp = u; u = f; f = d; d = b; b = temp;
  }
  void E(void) {
    int temp;
    temp = u; u = l; l = d; d = r; r = temp;
  }
  void W(void) {
    int temp;
    temp = u; u = r; r = d; d = l; l = temp;
  }
  void T(void) {
    int temp;
    temp = f; f = r; r = b; b = l; l = temp;
  }
};

int main() {

  Dice dice;
  std::string str;
  int m = 0;
  int N;
  int u, f;
  
  std::cin >> dice.u;
  std::cin >> dice.f;
  std::cin >> dice.r;
  std::cin >> dice.l;
  std::cin >> dice.b;
  std::cin >> dice.d;


  std::cin >> N;
  for(int i = 0; i < N; ++i) {
    std::cin >> u >> f;
    while( dice.u != u) {
      if( m == 0 ) {
	dice.N();
      }
      else {
	dice.E();
      }
      m = 1 - m;
    }
    while( dice.f != f ) {
      dice.T();
    }
    std::cout << dice.r << std::endl;
  }
      
  
  return 0;
}
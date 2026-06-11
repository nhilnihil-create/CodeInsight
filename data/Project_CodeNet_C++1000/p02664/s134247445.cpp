#include <iostream>
int main() {
std::string X; std::cin >> X;
 for(int i=0;i<X.size();i++) if(X[i] == '?')  X[i] = 'D';
  std::cout << X;
}

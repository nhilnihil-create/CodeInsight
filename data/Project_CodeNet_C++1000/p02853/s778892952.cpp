#include <iostream>

using namespace std;

int main(){
  int x, y;
  std::cin >> x >> y;

  int prize[205] = {0};
  prize[0] = 300000;
  prize[1] = 200000;
  prize[2] = 100000;
  int ans = prize[x-1] + prize[y-1];
  if( x == y && x == 1 ) ans += 400000;
  std::cout << ans << '\n';
  return 0;
}

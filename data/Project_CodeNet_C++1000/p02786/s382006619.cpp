#include <iostream>

using namespace std;

long solution(long H) {
  if (H == 1)
    return 1;
  if (H == 0)
    return 0;

  return 1 + 2 * solution(H / 2);
}

int main(int argc, char** argv) {
  long H;
  cin >> H;
  cout << solution(H) << endl;
  return 0;
}

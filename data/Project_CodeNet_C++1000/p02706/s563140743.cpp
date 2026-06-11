#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int Day, num, A;
  cin >> Day >> num;
  for (int i = 0; i < num; i++){
    cin >> A;
    Day -= A;
  }
  cout << ((Day >= 0)? Day : -1) << '\n';
  return 0;
}

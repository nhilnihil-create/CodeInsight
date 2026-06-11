#include <iostream>

using namespace std;

int main()
{
  int n;
  cin >> n;
  if(0 == (n & (n - 1)))
    cout << "No";
  else {
    cout << "Yes\n";

    cout << n + 1 << " " << 2 << '\n';
    cout << 2 << " " << 3 << '\n';
    cout << 3 << " " << 1 << '\n';
    cout << 1 << " " << n + 2 << '\n';
    cout << n + 2 << " " << n + 3 << '\n';
    for(int i = 4; i + 1 <= n; i += 2){
      cout << i << " " << i + 1 << '\n';
      cout << i + 1 << " " << 1 << '\n';
      cout << 1 << " " << n + i << '\n';
      cout << n + i << " " << n + i + 1 << '\n';
    }
    if(n % 2 == 0){
      int bit = (n ^ (n & (n - 1)));
      cout << n << " " << ((n ^ bit) ^ 1) << '\n';
      cout << n + bit << " " << n + n << '\n';
    }
  }
  return 0;
}

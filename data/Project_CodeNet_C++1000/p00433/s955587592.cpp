#include <iostream>
using namespace std;

int main()
{
  int p[2] = {0}, n;
  for (int i = 0; i < 2; i++){
    for (int j = 0; j < 4; j++){
      cin >> n;
      p[i] += n;
    }
  }
  cout << max(p[0], p[1]) << endl;
  return (0);
}
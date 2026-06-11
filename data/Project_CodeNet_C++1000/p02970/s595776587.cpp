#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int n, d;

  cin >> n;
  cin >> d;

  int i = 1;
  while(true){
    if(i * (2*d+1) >= n)
      break;
    i++;
  }
  cout << i << endl;
  return 0;
}

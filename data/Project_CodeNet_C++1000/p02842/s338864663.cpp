#include <iostream>
using namespace std;

int main()
{
  int N;
  cin >> N;
  
  int X = N * 100 / 108;
  if(X * 108 / 100 == N)
  {
    cout << X << endl;
  }
  else if((X + 1) * 108 / 100 == N)
  {
    cout << X + 1 << endl;
  }
  else
  {
    cout << ":(" << endl;
  }
}
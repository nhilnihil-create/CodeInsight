#include <iostream>
using namespace std;

int main()
{
  int A, B, M;
  cin >> A >> B >> M;
  
  int a[A], b[B], minA = 100000, minB = 100000;
  for(int i = 0; i < A; ++i)
  {
    cin >> a[i];
    if(minA > a[i]) minA = a[i];
  }
  for(int i = 0; i < B; ++i)
  {
    cin >> b[i];
    if(minB > b[i]) minB = b[i];
  }
  
  int min = minA + minB;
  for(int i = 0; i < M; ++i)
  {
    int x, y, c;
    cin >> x >> y >> c;
    if(min > a[x-1] + b[y-1] - c) min = a[x-1] + b[y-1] - c;
  }
  
  cout << min << endl;
}
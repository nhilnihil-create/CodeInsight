#include <bits/stdc++.h>
using namespace std;
int main()
{
  int N , a , b;
  cin >> N;
  for(int i = 1 ; i <= 9 ; i++)
  {
    a = N / i;
    b = N % i;
    if(b == 0 && a <= 9 && 1 <= a)
    {
      cout << "Yes" << endl;
      break;
    }
    if(i == 9)
    {
      cout << "No" << endl;
    }
  }
}
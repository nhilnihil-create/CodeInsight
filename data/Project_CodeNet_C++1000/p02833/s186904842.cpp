#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N;
  cin >> N;
  
  int64_t T;
  
  if((N % 2) == 1){cout << '0' << endl;}
  else
  {
    N -= N % 10;
    N /= 10;
    T += N;
    while(N != 0)
    {
      T += N / 5;
      if((N / 25) == 0){N = 0;}
      else{N /= 5;}
    }
    cout << T << endl;
  }
}
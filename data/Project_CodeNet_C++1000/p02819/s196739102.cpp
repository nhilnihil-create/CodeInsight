#include <bits/stdc++.h>
using namespace std;

bool isPrime[100005] = {};

int main()
{
  fill_n(isPrime, 100005, true);
  for (size_t i = 2; i < 100005; i++)
  {
    if (isPrime[i])
    {
      for (size_t j = 2 * i; j < 100005; j = j + i)
      {
        isPrime[j] = false;
      }
      
    }
    
  }
  int x; cin >> x;
  for (size_t i = x; i < 100005; i++)
  {
    //cout << "isPrime[" << i << "]: " << isPrime[i] << endl;
    if (isPrime[i])
    {
      cout << i << endl;
      return 0;
    }
    
  }
   
}
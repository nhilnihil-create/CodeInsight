#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long n;cin>>n;
  for (long long i = sqrt(n); i >= 0; i--)
  {
    if (n % i == 0)
    {
      cout << i + n / i - 2LL << endl;
      return 0;
    }
  }
  
}
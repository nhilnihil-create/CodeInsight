#include <iostream>
#include <cstring>
using namespace std;
typedef unsigned long long ull;

ull dp[100];

ull fib(int n) 
{
    if (n == 1 || n == 0) return 1;
    if (~dp[n]) return dp[n];
    return dp[n] = fib(n-1) + fib(n-2);
}

int main(void)
{
  int N;
  cin >> N;
  memset(dp, -1, sizeof(dp));
  cout << fib(N) << endl;
}
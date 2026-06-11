#include <iostream>
using namespace std;

const int MAX_N = 123456 * 2;
bool prime[MAX_N + 1];

void sieve()
{
  prime[0] = prime[1] = false;
  for(int i = 2; i <= MAX_N; i++)
    prime[i] = true;
  for(int i = 2; i <= MAX_N; i++)
    if(prime[i])
      for(int j = i * 2; j <= MAX_N; j += i)
	prime[j] = false;
}

int main()
{
  sieve();
  while(1){
    int n, ans = 0;
    cin >> n;
    if(n){
      for(int i = n + 1; i <= 2 * n; i++)
	if(prime[i])
	  ans++;
      cout << ans << endl;
    }else{
      break;
    }
  }
}
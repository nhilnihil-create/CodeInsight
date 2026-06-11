#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

int main(){
  const int MAX = 2 * 123456 + 10;
  vector<bool> isPrime( MAX, true );
  isPrime[0] = isPrime[1] = false;

  for(int i = 4; i < MAX; i += 2)
    isPrime[i] = false;

  for(int i = 3; i * i < MAX; i += 2)
    if(isPrime[i])
      for(int j = i + i; j < MAX; j += i)
        isPrime[j] = false;

  int n;

  while(scanf("%d", &n), n)
    printf("%d\n", count(isPrime.begin() + n + 1, isPrime.begin() + 2 * n + 1, true));

  return 0;
}
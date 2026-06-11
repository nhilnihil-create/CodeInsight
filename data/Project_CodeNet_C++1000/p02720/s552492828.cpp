#include <stdio.h>
#include <queue>
#include <string>

using namespace std;
typedef unsigned long long llong;

#define MAX 100001
const llong mod = 1000000000 + 7;

int main()
{
  int K;
  scanf("%d", &K);

  llong x;
  queue<llong> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);
  q.push(6);
  q.push(7);
  q.push(8);
  q.push(9);

  for (int i = 0; i < K; i++)
  {
    x = q.front();
    q.pop();

    if (x % 10 != 0)
      q.push(x * 10 + (x % 10) - 1);

    q.push(x * 10 + (x % 10));

    if (x % 10 != 9)
      q.push(x * 10 + (x % 10) + 1);
  }

  printf("%llu\n", x);

  return 0;
}
#include <iostream>

using namespace std;

int main(void)
{
 int N;
 int M;
  int ans = 0;
 cin >> N >> M;
  if(N >= 2)
  {
    ans = ans + N*(N-1)/2;
  }
    if(M >= 2)
  {
    ans = ans + M*(M-1)/2;
  }
  printf("%d\n",ans);
}
#include <stdio.h>
#include <queue>
using namespace std;

int main()
{
  priority_queue<int> q;
  int n,m; scanf ("%d %d",&n,&m);
  while (n--){
int x; scanf ("%d",&x); q.push(x);
  }
  while (m--){
int x = q.top(); q.pop(); q.push(x/2);
  }
  long long a = 0;
  while (!q.empty()){
a += q.top(); q.pop();
  }
  printf ("%lld\n",a);
return 0;
}
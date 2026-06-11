#include <cstdio>
#define rep(i,l,n) for(int i = l; i < (n); i++)
using namespace std;
using ll = long long;
int main() {
  int a = 100000,b = 200000,c = 300000;
  int x,y,ans = 0;
  scanf("%d %d",&x,&y);
  if(x == 3) ans += a;
  else if(x == 2) ans += b;
  else if(x == 1) ans += c;
  if(y == 3) ans += a;
  else if(y == 2) ans += b;
  else if(y == 1) ans += c;
  if(x == 1 && y == 1) ans += 400000;
  printf("%d\n",ans);
  return 0;
}
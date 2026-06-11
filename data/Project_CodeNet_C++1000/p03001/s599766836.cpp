#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int w,h,x,y;
  scanf("%d%d%d%d", &w, &h, &x, &y);
  printf("%lf %d\n", double(w)*double(h)/2, x*2==w && y*2==h);
 }

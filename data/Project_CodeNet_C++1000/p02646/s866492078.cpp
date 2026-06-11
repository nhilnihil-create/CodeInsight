#include <bits/stdc++.h>
using namespace std;
long long N = pow(10, 9);
int main(){
  long long a, v, b, w, t;
  scanf("%lld %lld", &a, &v);
  scanf("%lld %lld", &b, &w);
  scanf("%lld", &t);
 
  long long d = (v - w) * t;
  long long l = abs(a - b);
  if(d < l) printf("NO");
  else printf("YES");
}
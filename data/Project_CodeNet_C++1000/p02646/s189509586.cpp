#include<bits/stdc++.h>
using namespace std;
long long a, b, v, w, t;
int main()
{
  scanf("%lld%lld%lld%lld%lld", &a, &v, &b, &w, &t);
  if(v <= w) return printf("NO\n"), 0;
  long long d = abs(a - b);
  if(t * (v - w) >= d) printf("YES\n");
  else printf("NO\n");
  return 0;
}
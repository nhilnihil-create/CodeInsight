#include <cstdio>
#include <algorithm>

int main()
{
  long long a,v,b,w,t;
  scanf("%lld%lld%lld%lld%lld",&a,&v,&b,&w,&t);
  puts(std::abs(a-b)<=(v-w)*t?"YES":"NO");
  return 0;
}

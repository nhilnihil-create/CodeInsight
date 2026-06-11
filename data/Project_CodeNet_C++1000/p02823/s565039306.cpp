#include <cstdio>
#include <algorithm>

int main()
{
  long long N,a,b;
  scanf("%lld%lld%lld",&N,&a,&b);
  long long ans;
  if(a%2==b%2){
    ans=(std::max(a,b)-std::min(a,b))/2ll;
  }
  else{
    ans=std::min((a+b-1)/2ll,(2*N-a-b+1)/2ll);
  }
  printf("%lld\n",ans);
  return 0;
}

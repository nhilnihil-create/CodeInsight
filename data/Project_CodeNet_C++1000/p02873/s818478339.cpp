#include <cstdio>
#include <cstring>
#include <vector>

int main()
{
  static char s[1000000];
  scanf("%s",s);
  int n=strlen(s);
  std::vector<int> a(n+1),b(n+1);
  a[0]=0;
  for(int i=0;i<n;i++){
    a[i+1]=(s[i]=='<'?a[i]+1:0);
  }
  b[n]=0;
  for(int i=n-1;i>=0;i--){
    b[i]=(s[i]=='>'?b[i+1]+1:0);
  }
  long long ans=0ll;
  for(int i=0;i<=n;i++){
    ans+=std::max(a[i],b[i]);
  }
  printf("%lld\n",ans);
  return 0;
}

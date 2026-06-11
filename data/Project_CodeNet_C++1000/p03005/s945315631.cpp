#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
main()
{
  int n,k,ans;
  scanf("%d %d",&n,&k);
  if(k==1)
  {
    printf("0");
    return 0;
  }
  ans=n-k;
  printf("%d",ans);
}

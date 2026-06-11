#include <cstdio>
#include <vector>


int main()
{
  int n,k;
  scanf("%d%d",&n,&k);
  std::vector<int> a(n);
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(int t=0;t<k;t++){
    std::vector<int> s(n+1,0);
    for(int i=0;i<n;i++){
      s[std::max(0,i-a[i])]++;
      s[std::min(n,i+a[i]+1)]--;
    }
    a[0]=s[0];
    bool F=true;
    for(int i=1;i<n;i++){
      a[i]=a[i-1]+s[i];
      if(a[i]<n){
	F=false;
      }
    }
    if(F)
      break;
  }
  for(int i=0;i<n;i++){
    printf("%d%c",a[i],i<n-1?' ':'\n');
  }
  return 0;
}

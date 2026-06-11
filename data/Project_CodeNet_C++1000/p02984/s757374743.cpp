#include<queue>
#include<stack>
#include<math.h>
#include<cmath>
#include<bitset>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<utility>
#include<functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  ll n,a[100010],i,ans[100010],k=0;
  scanf("%lld\n",&n);
  for(i=0;i<n;i++){
    scanf("%lld ",&a[i]);
  }
  for(i=1;i<n;i++){
    k+=a[i]-a[i-1];
    i++;
  }
  k+=a[0]-a[n-1];
  ans[0]=(a[0]-k)/2;
  for(i=1;i<n;i++){
    ans[i]=a[i-1]-ans[i-1];
  }
  for(i=0;i<n;i++){
    if(i==0){
      printf("%lld",ans[i]*2);
    }
    else{
      printf(" %lld",ans[i]*2);
    }
  }
  printf("\n");
  return 0;
}
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
using namespace std;
int main(){
  long long int mod=1000000007,ans=1,n,a[100010],b[100010],i;
  scanf("%lld\n",&n);
  for(i=0;i<n;i++){
    b[i]=0;
    scanf("%lld\n",&a[i]);
  }
  b[0]=3;
  for(i=0;i<n;i++){
    ans=ans*b[a[i]]%mod;
    b[a[i]+1]++;
    b[a[i]]--;
  }
  printf("%lld\n",ans);
  return 0;
}
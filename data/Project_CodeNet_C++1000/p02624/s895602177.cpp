#include<bits/stdc++.h>
using namespace std;

int main(){
  long N;
  scanf("%ld",&N);
  long ans=0;
  for(long j=1;j<=N;j++){
    long X=N/j;
    ans+=(X*(X+1)/2)*j;
  }
  printf("%ld\n",ans);
}

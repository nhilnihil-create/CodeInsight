#include<bits/stdc++.h>
using namespace std;

int main(){
  long N;
  scanf("%ld",&N);
  long ans=0;
  for(long i=1;i<=N;i++){
    if(i%3!=0 && i%5!=0) ans+=i;
  }
  printf("%ld",ans);
}

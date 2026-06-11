#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#define MAXN 300000
using namespace std;
int prime[MAXN];
bool is_prime[MAXN];
int sum_prime[MAXN];
int sieve(int n){
  int p=0;
  for(int i=0;i<=n;i++) is_prime[i]=true;
  is_prime[0]=is_prime[1]=false;
  for(int i=2;i<=n;i++){
    if(is_prime[i]){
      prime[p++]=i;
      for(int j=2*i;j<=n;j+=i) is_prime[j]=false;
    }
  }
  return p;

}
int main(void){
  int n,i;
  sieve(MAXN);
  for(i=1;i<MAXN;i++){
    sum_prime[i]=sum_prime[i-1]+is_prime[i];
  }
  while(scanf("%d",&n),n){
    printf("%d\n",sum_prime[2*n]-sum_prime[n]);
  }
  return 0;
}
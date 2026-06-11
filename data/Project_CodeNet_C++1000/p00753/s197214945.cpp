#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define mod 1000000007 //1e9+7
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 201

const int MAX_P = 123456 * 2; //max
int prime[MAX_P+1];

void Eratosthenes(void){
  for(int i=2;i<=MAX_P;i++)
    prime[i]=true;
  
  for(int i=2;i*i<=MAX_P;i++)
    if(prime[i])  
      for(int j=i;i*j<=MAX_P;j++)
	prime[i*j]=false;
}

void calc(int n){
  int ans = prime[2*n] - prime[n];
  
  printf("%d\n",ans);
}

int main(){
  int n;
  
  Eratosthenes();

  for(int i=0;i<123456*2;i++) prime[i+1] += prime[i];
  
  while(1){
    scanf("%d",&n);
    if(n==0) break;
    calc(n);
  }
  
  return 0;
}
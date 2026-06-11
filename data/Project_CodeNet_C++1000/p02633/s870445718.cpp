#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int gcd(int a,int b){return b?gcd(b,a%b):a;}

void work(){
  int n;
  scanf("%d",&n);
  printf("%d\n",360/gcd(n,360));
}

int main(){
  int T=1;
  //scanf("%d",&T);
  for (;T--;) work();
  return 0;
}
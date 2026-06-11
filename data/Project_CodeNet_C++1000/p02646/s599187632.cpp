#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int main(){
  LL a,b,v,w,t;
  scanf("%lld%lld%lld%lld%lld",&a,&v,&b,&w,&t);
  puts((v-w)*t>=abs(a-b)?"YES":"NO");
  return 0;
}
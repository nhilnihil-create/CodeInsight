#include<stdio.h>
#include<iostream>
#include<valarray>
#include<cmath>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
valarray<ll>data;
void proc(){
  ll p1=data.sum();
  ll p2=pow(data,(ll)2).sum();
  ll p3=pow(data,(ll)3).sum();
  ll pi=*max_element(begin(data),end(data));
  printf("%Ld\n%Lf\n%Lf\n%Ld\n",p1,sqrt((ld)p2),cbrt((ld)p3),pi);
}
int main(){
  int x;
  cin>>n;
  data=valarray<ll>(n);
  for(int i=0;i<n;++i)cin>>data[i];
  for(int i=0;i<n;++i){cin>>x;data[i]-=x;data[i]=data[i]>0?data[i]:-data[i];}
  proc();
  return 0;
}
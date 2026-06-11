#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,a;
  double ans;
  cin>>N;
  a=(N+2-1)/2;
  ans=(double)a/N;
  printf("%.10f\n",ans);
}
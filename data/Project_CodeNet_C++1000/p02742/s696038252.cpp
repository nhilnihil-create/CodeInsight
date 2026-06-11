#include<bits/stdc++.h>
using namespace std;
int main(void){
  long long h,w; cin>>h>>w;
  long long res=(h*w+1)/2;
  if(min(h,w)==1) res=1;
  cout<<res;
  return 0;
}
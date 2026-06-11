#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t h,w;
  cin>>h>>w;
  cout<<(h==1||w==1?1:(h*w+1)/2)<<endl;
}
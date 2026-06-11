#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  int h,a;
  cin>>h>>a;
  int cnt=0;
  while(h>0){
    h-=a;
    cnt++;
  }
  cout<<cnt<<endl;
  return 0;
}
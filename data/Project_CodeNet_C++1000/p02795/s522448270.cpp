#include<iostream>
using namespace std;

int main(){
  int h,w,n;
  cin>>h>>w>>n;
  int sum=0;
  int cnt=0;
  while(sum<n){
    sum+=max(h,w);
    cnt++;
  }
  cout<<cnt<<endl;
  return 0;
}
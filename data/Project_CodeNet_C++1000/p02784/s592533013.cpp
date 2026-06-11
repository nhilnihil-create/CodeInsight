#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,n;
  cin>>h>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a.at(i);
  }
  int sum=0;
  for(int i=0;i<n;i++){
    sum=sum+a.at(i);
  }
  if(sum>=h){
    cout<<"Yes";
  }else{
    cout<<"No";
  }
}
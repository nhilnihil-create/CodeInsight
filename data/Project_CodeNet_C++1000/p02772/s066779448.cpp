#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a.at(i);
  }
  int flag=1;
  for(int i=0;i<n;i++){
    if(a.at(i)%2==0){
      if(a.at(i)%3!=0&&a.at(i)%5!=0){
        flag=0;
      }
    }
  }
  if(flag==1){
    cout<<"APPROVED";
  }else{
    cout<<"DENIED";
  }
}
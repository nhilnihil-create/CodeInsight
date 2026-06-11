#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,n,k;
  cin>>x>>n;
  set<int> s;
  for(int i=0;i<n;i++){
    cin>>k;
    s.insert(k);
  }
  int index;
  int mm=INT_MAX;
  for(int i=x;i>=-1000;i--){
    if(s.count(i)==0){
      if(mm>abs(x-i)){
        mm=abs(x-i);
        index=i;
        break;
      }
    }
  }
  for(int i=x;i<=1000;i++){
    if(s.count(i)==0){
      if(mm>abs(x-i)){
        mm=abs(x-i);
        index=i;
        break;
      }
    }
  }
  cout<<index;
  return 0;
}
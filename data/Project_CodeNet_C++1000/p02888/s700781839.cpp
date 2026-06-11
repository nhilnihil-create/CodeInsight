#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int>l(n);
  vector<int>a(1001);
  for(int i=0;i<n;i++){
    cin >> l.at(i);
    a.at(l.at(i))++;
  }
  int64_t ans=0;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(i!=j){
      for(int k=abs(l.at(i)-l.at(j))+1,x=min(1001,(l.at(i)+l.at(j)));k<x;k++){
        ans+=a.at(k);
        if(k==l.at(i)) ans--;
        if(k==l.at(j)) ans--;
      }
      }
    }
  }
  cout << ans/3 << endl;
  return 0;
}
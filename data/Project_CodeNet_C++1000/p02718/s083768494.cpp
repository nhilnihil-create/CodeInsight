#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,m;
  cin>>n>>m;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a.at(i);
  }
  int s=0;
  for(int i=0;i<n;i++){
    s=s+a.at(i);
  }
  int cnt=0;
  for(int i=0;i<n;i++){
    if((s-1+4*m)/(4*m)<=a.at(i)){
      cnt++;
    }
  }
  if(cnt>=m){
    cout<<"Yes";
  }else{
    cout<<"No";
  }
}
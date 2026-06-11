#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,m;
  cin>>n>>m;
  vector<int> a(m);
  for(int i=0;i<m;i++){
    cin>>a.at(i);
  }
  for(int i=0;i<m;i++){
    n=n-a.at(i);
  }
  if(n>=0){
    cout<<n;
  }else{
    cout<<"-1";
  }
}
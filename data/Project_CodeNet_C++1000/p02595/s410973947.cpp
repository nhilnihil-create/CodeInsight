#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long n,d,ans;
  ans=0;
  cin>>n>>d;
  vector<vector<long long>> a(n, vector<long long>(2));
  for(int i=0;i<n;i++){
    for(int j=0;j<2;j++){
      cin>>a.at(i).at(j);
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<2;j++){
      if(a.at(i).at(j)<0){
        a.at(i).at(j)=-a.at(i).at(j);
      }
    }
  }
  for(int i=0;i<n;i++){
    if(d*d>=a.at(i).at(0)*a.at(i).at(0)+a.at(i).at(1)*a.at(i).at(1)){
      ans++;
    }
  }
  cout<<ans;
}
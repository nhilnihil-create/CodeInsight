#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> x(n),y(n);
  for(int i=0;i<n;i++){
    cin >> x[i] >> y[i];
  }
  map<pair<int,int>,int> mp;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i==j){
        continue;
      }
      mp[make_pair(x[i]-x[j],y[i]-y[j])]++;
    }
  }
  int t=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i==j){
        continue;
      }
      t=max(t,mp[make_pair(x[i]-x[j],y[i]-y[j])]);
    }
  }
  cout << n-t << endl;
}
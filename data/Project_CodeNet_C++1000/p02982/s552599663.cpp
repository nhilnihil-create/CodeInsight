#include<bits/stdc++.h>
using namespace std;
int main() {
  int n,d,i,j,k,l,ans=0;
  set<int> s;
  cin>>n>>d;
  vector<vector<int>> x(n,vector<int>(d));
  for(i=0;i<n;i++) for(j=0;j<d;j++) cin>>x.at(i).at(j);
  for(i=0;i*i<=16000;i++) s.insert(i*i);
  for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++){
      l=0;
      for(k=0;k<d;k++) l+=(x.at(i).at(k)-x.at(j).at(k))*(x.at(i).at(k)-x.at(j).at(k));
      if(s.count(l)) ans++;
    }
  }
  cout<<ans<<endl;
}
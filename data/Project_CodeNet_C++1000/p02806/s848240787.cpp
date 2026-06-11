#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<pair<string,int>>a(n);
  int sum=0;
  for(int i=0;i<n;i++){
    cin>>a[i].first>>a[i].second;
    sum+=a[i].second;
  }
  string x;
  cin>>x;
  int ans=0;
  for(int i=0;i<n;i++){
    ans+=a[i].second;
    if(x==a[i].first) break;
  }
  cout<<sum-ans<<endl;
}

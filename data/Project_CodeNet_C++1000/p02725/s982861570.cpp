#include<bits/stdc++.h>
using namespace std;
int main(){
  int k,n;
  cin>>k>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++){
    cin>>a.at(i);
  }
    a.push_back(a.at(0)+k);
    int l=0;
    for(int i=0;i<n;i++){
      l=max(l,a.at(i+1)-a.at(i));
            }
  int ans=k-l;
  cout<<ans<<endl;
}
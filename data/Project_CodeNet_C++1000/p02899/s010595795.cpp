#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0; i<n; i++){
    cin>>a.at(i);
  }
  vector<int> ans(n,0);
  for(int i=0; i<n; i++){
    ans.at(a.at(i)-1)=i+1;
  }
  for(int i=0; i<n; i++){
    cout<<ans.at(i)<<" ";
  }
}

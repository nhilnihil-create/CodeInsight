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
    int j;
    j=a.at(i);
    ans.at(j-1)=i+1;
  }
  for(int i=0; i<n; i++){
    cout<<ans.at(i)<<" ";
  }
}

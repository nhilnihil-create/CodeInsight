#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  int ans=0;
  
  cin>>n>>k;
  vector<int> s(n);
  for(int i=0;i<n;i++){
    cin>>s.at(i);
  }
  sort(s.begin(),s.end());
  
  for(int i=0;i<k;i++){
    ans+=s.at(i);
  }
  cout<<ans<<endl;
}

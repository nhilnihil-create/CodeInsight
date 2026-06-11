#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  int l,r;
  vector<pair<int,int>> ns(n);
  for(int i=0;i<n;i++){
    cin>>l>>r;
    ns[i].second=l-r;//右端をsecondに
    ns[i].first=l+r;
  }
  sort(ns.begin(),ns.end());
  int index=1;
  int ans=0;
  int leftend=ns[0].first;
  while(index<n){
    if(leftend>ns[index].second){
      ans++;
    }
    else leftend=ns[index].first;
    index++;
  }
  cout<<n-ans<<endl;
  return 0;
}


   
    
  
 
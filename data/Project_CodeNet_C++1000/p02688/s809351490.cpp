#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k; cin>>n>>k;
  vector<int> sweet(n);
  for(int i=0;i<k;i++){
    int d; cin>>d;
    vector<int> a(d);
    for(int &j:a)
      cin>>j;
    for(int j:a)
      sweet[j-1]++;
  }
  int ans=0;
  for(int i:sweet){
    if(i==0)
      ans++;
  }
  cout<<ans<<endl;
}
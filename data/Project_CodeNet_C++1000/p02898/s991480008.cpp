#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin>>n>>k;
  int ans=0;
  vector<int> a;
  for(int i=0;i<n;i++){
    int b;
    cin>>b;
    a.push_back(b);
  }
  for(int i=0;i<n;i++){
    if(a[i]>=k){
      ans++;
    }
  }
  cout<<ans<<endl;
}
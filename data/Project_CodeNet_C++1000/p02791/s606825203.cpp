#include<bits/stdc++.h>

using namespace std;

int main(){
  int n; cin>>n;
  int mn=n+1;
  int ans=0;
  for(int i=0;i<n;i++){
    int x;cin>>x;
    if(x<mn){
     ans++;
     mn=x;

    }

  }  cout<<ans;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin>>n;
  vector<int> h(n);
  rep(i,n){
    cin>>h[i];
  }
  reverse(h.begin(),h.end());
  bool ans=true;
  rep(i,n-1){
    if(h[i+1]-h[i]>=2){
      ans=false;
    }else if(h[i+1]-h[i]==1){
      h[i+1]--;
    }
  }
  if(ans){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}
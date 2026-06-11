#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
  int n,m;cin>>n>>m;
  vector<int> h(n);
  vector<bool> good(n,true);
  int ans=0;
  rep(i,n) cin>>h.at(i);
  
  for(int i=0; i<m; i++){
    
    int a,b; cin>>a>>b;
    int low;
    if(h.at(a-1)<h.at(b-1)){
      good.at(a-1)=false;

    } else if(h.at(b-1)<h.at(a-1)){
      good.at(b-1)=false;
    } else {
      good.at(a-1)=false;
      good.at(b-1)=false;
    }
  }
  for(int i=0;i<n;i++){
    if(good.at(i)==true) {
      ans++;
      //cout << i+1<<endl;
    }
  }
  cout<< ans;
}
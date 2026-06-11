#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double lld;
ll MOD = (1e9)+7;
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
inline void fastIO(){
  ios_base::sync_with_stdio(0);cin.tie(0);
}

int main(){
  fastIO();
  int n;
  cin>>n;
  vector<int>h(n);
  for(int i=0;i<n;i++){
    cin>>h[i];
  }
  for(int i=0;i<n-1;i++){
    if(h[i+1]<h[i]){
      h[i]--;
    }else if(i>0){
      if(h[i+1]==h[i]&&h[i]>h[i-1]){
        h[i]--;
      }
    }

  }
  bool yes=true;
  for(int i=0;i<n-1;i++){
    if(h[i+1]<h[i]){
      yes=false;
    }
  }
  if(yes){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}
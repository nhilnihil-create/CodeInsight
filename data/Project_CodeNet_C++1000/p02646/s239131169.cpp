#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
const ll INF = 10e9;

int main(){
  ll a,b,v,w,t;
  cin>>a>>v>>b>>w>>t;
  if (v<=w){
    cout << "NO" << endl;
    return 0;
  }
  else{
    if ( abs(a-b) <= t*(v-w) ){
      cout << "YES" << endl;
      return 0;
    }
    else{
      cout << "NO" << endl;
      return 0;
    }
  }
}
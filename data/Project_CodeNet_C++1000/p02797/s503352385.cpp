#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
using pii = pair<int, int>;

int main() {
  int n,k,s; cin>>n>>k>>s;
  if(s!=1000000000){
    rep(i,k){cout<<s<<" ";}
    rep(i,n-k){cout<<s+1<<" ";}
  }
  else{
    rep(i,k){cout<<s<<" ";}
    rep(i,n-k){cout<<1<<" ";}
  }
}
     
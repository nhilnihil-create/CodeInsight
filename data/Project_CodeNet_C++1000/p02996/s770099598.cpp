#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
using pii = pair<int, int>;

int main() {
  int n; cin>>n;
  vector<pii> v(n);
  rep(i,n){
    cin>>v[i].second>>v[i].first;
  }
  sort(v.begin(), v.end());
  rep(i,n-1){
    v[i+1].second+=v[i].second;
  }
  bool b=true;
  rep(i,n){
    if(v[i].first<v[i].second){b=false;break;}
  }
  if(b){cout<<"Yes"<<endl;}
  else{cout<<"No"<<endl;}
}
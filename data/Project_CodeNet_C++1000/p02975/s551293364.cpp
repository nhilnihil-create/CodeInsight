#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(ll i=0; i<(ll)(n); i++)
ll l=1000000007;
string alphabet="abcdefghijklmnopqrstuvwxyz";

int main() {
  int n; cin>>n;
  set<int> s;
  vector<pii> v;
  rep(i,n){
    int a; cin>>a; 
    s.insert(a);
    if(v.size()<s.size()){pii p= make_pair(a,1);v.push_back(p);}
    else{
      rep(j,v.size()){
        if(v[j].first==a){v[j].second++;}
      }
    }
        
  }
  if(v.size()>3){cout<<"No";}
  else if(v.size()==1){
    if(v[0].first==0){cout<<"Yes";}
    else{cout<<"No";}
  }
  else if(v.size()==2){
    if(n%3==0 && v[0].first*v[1].first==0){
      if(v[0].second*2==v[1].second 
         || v[1].second*2==v[0].second){cout<<"Yes";}
      else{cout<<"No";}
    }
    else{cout<<"No";}
  }
  else if(v.size()==3){
    bitset<17> x(v[0].first);
    bitset<17> y(v[1].first);
    bitset<17> z(v[2].first);
    if(v[0].second==v[1].second && v[1].second==v[2].second
      &&((x ^ y) ==z||(y ^ z)==x||(z ^ x) ==y )){cout<<"Yes";}
    else{cout<<"No";}
  }
}


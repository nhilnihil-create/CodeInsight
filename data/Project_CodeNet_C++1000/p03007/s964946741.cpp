#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  int n;
  cin >> n;
  vector<int> p,ne;
  vector<P> res;
  rep(i,n){
    int x;cin >> x;
    if(x >= 0)p.push_back(x);
    else ne.push_back(x);
  }
  if(p.size() >= 2 && ne.size() >= 1){
    int o = ne[0];
    for(int i = 0;i < p.size()-1;i++){
      res.push_back(make_pair(o,p[i]));
      o = o-p[i];
    }
    res.push_back(make_pair(p.back(),o));
    o = p.back()-o;
    for(int j = 1;j < ne.size();j++){
      res.push_back(make_pair(o,ne[j]));
      o = o-ne[j];
    }
    cout << o << endl;
    for(P k : res)cout << k.first << " " << k.second << endl;
  }else if(p.size() == 1){
    int o = p[0];
    for(auto au : ne){
      res.push_back(make_pair(o,au));
      o = o-au;
    }
    cout << o << endl;
    for(P k : res)cout << k.first << " " << k.second << endl;
  }else if(p.size() >= 2 && ne.size() == 0){
    sort(ALL(p));
    int o = p[0];
    for(int i = 1;i < p.size()-1;i++){
      res.push_back(make_pair(o,p[i]));
      o = o-p[i];
    }
    res.push_back(make_pair(p.back(),o));
    o = p.back()-o;
    cout << o << endl;
    for(P k : res)cout << k.first << " " << k.second << endl;
  }else if(p.size() == 0){
    sort(ALL(ne),greater<int>());
    int o = ne[0];
    for(int i = 1;i < ne.size();i++){
      res.push_back(make_pair(o,ne[i]));
      o = o-ne[i];
    }
    cout << o << endl;
    for(P k : res)cout << k.first << " " << k.second << endl;
  }




  return 0;
}
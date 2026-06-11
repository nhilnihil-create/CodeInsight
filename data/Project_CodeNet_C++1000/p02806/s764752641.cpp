#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;

int main(){
  int n;
  cin>>n;
  vector<pair<string,int>> st(n);
  int t_all=0;
  rep(i,n){
    cin>>st[i].first>>st[i].second;
    t_all+=st[i].second;
  }
  string x;
  cin >> x;
  int t_wake=0;

  rep(i,n){
    t_wake+=st[i].second;
    if(st[i].first==x){
      cout<<t_all-t_wake<<endl;
      break;
    }
  }




}

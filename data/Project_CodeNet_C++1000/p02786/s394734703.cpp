#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;
const int INF=1e9;

ll AttackTime(ll h){
  if(h==1){
    return 1;
  }else{
    return 2*AttackTime(h/2)+1;
  }
}


int main(){
  ll h;
  cin>>h;
  cout<<AttackTime(h);
  
}

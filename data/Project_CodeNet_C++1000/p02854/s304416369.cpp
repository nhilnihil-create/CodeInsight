#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;
const int INF=1e9;

int main(){
  ll n;
  cin>>n;
  vector<ll> a(n);
  ll s=0;
  rep(i,n){
    cin>>a[i];
    s+=a[i];
  }
  ll minx=s,sum=0;
  rep(i,n){
    sum+=a[i];
    minx=min(minx,abs(sum-(s-sum)));
  }
  cout<<minx <<endl;
  return 0;

}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  ll ub = 2e9;
  ll lb = 0;
  rep(i,100){
    ll mid = (ub+lb)/2;
    if(mid==0) break;
    ll tans = 0;
    rep(j,n){
      if(a[j]>mid){
        tans += (a[j]+mid-1)/mid-1;
      }
    }
    if(tans>k) lb = mid;
    else ub = mid;
  }
  cout << ub << endl;

  return 0;
    

}

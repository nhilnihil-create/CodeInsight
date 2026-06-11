#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  ll n,k;
  cin >> n >> k;
  vector<ll>a(n);
  rep(i,0,n) cin >> a[i];
  sort(a.begin(),a.end());
  ll lb = 1; //lower bound(下限)
  ll ub = a[n-1]+1; //upper bound(上限)
  ll mid = (lb+ub)/2; //ここで二分
  while(lb < ub){
    ll cnt = 0;
    rep(i,0,n){
      cnt += (a[i]-1)/mid;
    }
    if(cnt <= k){
      ub = mid; 
      mid = (lb+ub)/2;
    }
    else{
      lb = mid+1;
      mid = (lb+ub)/2;
    }
  }
  cout << lb << endl;
}
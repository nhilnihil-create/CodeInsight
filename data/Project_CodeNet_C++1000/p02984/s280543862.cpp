#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);

  vector<ll> ans(n);
  ll sum=0;

  for(int i=0; i<n; i++){
    sum += (pow(-1, i))*a.at(i);
  }

  rep(i, n){
    ans.at(i) = sum;
    sum = sum * -1;
    sum += a.at(i)*2;
  }

  rep(i, n) cout << ans.at(i) << " ";

}
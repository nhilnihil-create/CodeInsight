#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n, k;
  cin>>n>>k;
  vector<int> p(n);
  rep(i,n) cin>>p.at(i);
  int summ = 0, sum = 0;
  rep(i, n){
    if(i<k){
      sum+=p.at(i);
      summ=sum;
    }
    else{
      sum=sum + p.at(i) - p.at(i-k);
      if(summ<sum) summ = sum;
    }
  }
  double ans = 0.5*(summ+k);
  cout<<fixed<<setprecision(2);
  cout<<ans<<endl;
}
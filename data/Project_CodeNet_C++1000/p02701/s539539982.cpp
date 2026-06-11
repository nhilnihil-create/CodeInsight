#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main() {

  ll n; cin>>n; ll ans=n; ll ka=0;  
  vector<string>a(n);  
  rep(i,n) {
    cin>>a.at(i);  
  }
  
  sort(all(a));
  rep(i,n-1){if(a.at(i)==a.at(i+1))ka++;}
  
  
  
  cout<<ans-ka<<endl;
  
  
  
  
  
  
}

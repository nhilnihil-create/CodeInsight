#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 1e18;
#define all(v) v.begin(), v.end()

int main(){
  string s,t;
  cin >> s >> t;
  vector<vector<ll>> A(26);
  rep(i,s.size()){
    A.at(s.at(i)-'a').push_back(i);
  }
  ll ans=0,k=0;
  rep(i,t.size()){
    if(A.at(t.at(i)-'a').size()==0){
      cout << -1 << endl;
      return 0;
    }
    if(lower_bound(all(A.at(t.at(i)-'a')),k)!=A.at(t.at(i)-'a').end()){
      k=*lower_bound(all(A.at(t.at(i)-'a')),k);
      k++;
      if(k==s.size()){
        k=0;
        ans++;
      }
    }else{
      ans++;
      k=*lower_bound(all(A.at(t.at(i)-'a')),0);
      k++;
    }
  }
  cout << ans*s.size()+k << endl;
}
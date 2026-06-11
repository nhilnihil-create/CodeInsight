#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
#define all(v) v.begin(),v.end()

int main(){
  int N;cin>>N;
  vector<pair<string,int>> m(N);
  rep(i,N){
    string s;int t;cin>>s>>t;
    m[i] = {s,t};
  }
  string X;cin>>X;
  bool flag = false;
  ll ans = 0;
  rep(i,N){
    if(flag) ans += m[i].second;
    if(m[i].first==X) flag = true;
  }
  cout << ans << endl;
}
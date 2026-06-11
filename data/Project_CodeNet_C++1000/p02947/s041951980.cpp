#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

using vi=vector<int>;
using vll=vector<ll>;
using vvi=vector<vi>;

int main() {
  int N; cin >>N;
  vector<string> s(N);
  map<string,ll> a;
  rep(i,0,N) {
    cin >>s[i];
    sort(s[i].begin(),s[i].end());
    a[s[i]]++;
  }
  ll ans=0;
  for (auto p : a) {
    auto v=p.second;
    ans+=v*(v-1)/2;
  }
  cout <<ans <<endl;
  return 0;
}

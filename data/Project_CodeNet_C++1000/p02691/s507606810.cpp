#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using vb=vector<bool>;
using vvb=vector<vb>;
using pii = pair<int,int>;
using pli = pair<ll,int>;
using pll = pair<ll,ll>;
using vpii = vector<pii>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

int main() {
  int N;
  cin >> N;
  vi A(N);
  vi v;
  rep(i,N) {
    cin >> A[i];
    if(i>A[i]) v.push_back(i-A[i]);
  }
  sort(v.begin(),v.end());
  
  ll ans=0;
  rep(i,N)
    ans+=upper_bound(v.begin(),v.end(),i+A[i])-lower_bound(v.begin(),v.end(),i+A[i]);
  
  cout << ans << endl;
}
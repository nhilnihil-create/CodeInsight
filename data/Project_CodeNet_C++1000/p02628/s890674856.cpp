#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using pii = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back

int main() {
  vi p(1010);
  int n,k,ans=0; cin>>n>>k;
  rep(i,n) cin>>p[i];
  sort(p.begin(),p.begin()+n);
  rep(i,k) ans+=p[i];
  cout<<ans<<endl;
}

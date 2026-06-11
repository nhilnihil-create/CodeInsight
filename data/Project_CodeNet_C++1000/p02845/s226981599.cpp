#include<bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
#define ll long long
using namespace std;

const int MOD=1000000007;

int main() {
  int n; cin>>n;
  vector<int> a(n);
  rep(i, n) cin>>a[i];

  ll res=1;
  vector<int> x(3, 0);
  rep(i, n) {
    int cnt=0;
    rep(j, 3) if (a[i]==x[j]) cnt++;
    res*=cnt;
    res%=MOD;
    rep(j, 3) {
      if (a[i]==x[j]) {
        x[j]++;
        break;
      }
    }
  }
  cout<<res<<endl;
}

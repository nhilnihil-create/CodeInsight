#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const ll INF=1e18;

int main() {
  string	n;
  ll ans = 0;
  cin >> n;
  rep(i,n.size()){
    ans+=n[i] - '0';
  }
  if(ans%9==0) cout << "Yes" <<endl;
  else cout << "No" << endl;
}
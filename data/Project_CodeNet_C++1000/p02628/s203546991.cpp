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
  priority_queue<int,vector<int>,greater<int>> PQ;
  int n,k; cin>>n>>k;
  int p,ans=0,t;
  rep(i,n) {
    cin>>p;
    PQ.push(p);
  }
  rep(i,k) {
    t=PQ.top();
    PQ.pop();
    ans+=t;
  }
  cout<<ans<<endl;
}

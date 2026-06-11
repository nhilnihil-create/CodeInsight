#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n,k;
  cin >> n >> k;
  priority_queue<int> q;
  vector<vector<int>> v(k);
  rep(i,n){
    int x,y;
    cin >> x >> y;
    int z=k-x;
    if(z>=0) v[z].push_back(y);
  }
  ll ans=0;
  for(int i=k-1;i>=0;i--){
    for(int x:v[i]){
      q.push(x);
    }
    if(!q.empty()){
     int y=q.top();q.pop();
     ans+=y;
    }
  }
  cout << ans << endl;
}
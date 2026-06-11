#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;


int main(){
  ll n,m;
  cin >> n >> m;
  vector<ll>a[m];
  for(int i=0; i<n; i++){
    ll b,c;
    cin >> b >> c;
    if(b>m)continue;
    a[m-b].push_back(c);
  }
  priority_queue<ll>que;
  ll ans=0;
  for(int i=m-1; i>=0; i--){
    for(int b : a[i]) que.push(b);
    if(!que.empty()){
      ans += que.top();
      que.pop();
    }
  }
  
  
  cout << ans << endl;
}
  
  
  

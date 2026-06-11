#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

int main(){
  ll x,y,a,b,c;
  cin >> x >> y >> a >> b >> c;
  vector<ll>p(a),q(b);
  priority_queue<ll>r,color;
  for(int i=0; i<a; i++) cin >> p[i];
  for(int i=0; i<b; i++) cin >> q[i];
  for(int i=0; i<c; i++){
    ll z;
    cin >> z;
    r.push(z);
  }
  sort(p.begin(),p.end());
  reverse(p.begin(),p.end());
  sort(q.begin(),q.end());
  reverse(q.begin(),q.end());
  for(int i=0; i<x; i++) color.push(p[i]);
  for(int i=0; i<y; i++) color.push(q[i]);
  
  ll ans=0;
  for(int i=0; i<x+y; i++){
    if(r.size()==0){
      ll v;
      v=color.top();
      color.pop();
      ans+=v;
    }
    else{
      ll v,w;
      v=color.top();
      w=r.top();
      if(v>w){
        color.pop();
        ans+=v;
      }
      else{
        r.pop();
        ans+=w;
      }
    }
  }
  
  cout << ans << endl;
  
}
  

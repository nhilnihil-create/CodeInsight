#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9+7;
typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<lli> vlli;
typedef vector<bool> vb;
long long int max(long long int a,long long int b){
  if(a>b)
    return a;
  else
    return b;
}
long long int min(long long int a,long long int b){
  if(a<b)
    return a;
  else
    return b;
}
long long int binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a % m;
      a = a * a % m;
      b >>= 1;
    }
  return res;
}
long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}
 
//############################ENDOFTEMPLATE############################

void solve(){
  int x,y,a,b,c;
  cin>>x>>y>>a>>b>>c;

  vi p(a),q(b),r(c);
  for(int i = 0;i<a;i++){
    cin>>p[i];
  }

  for(int i = 0;i<b;i++){
    cin>>q[i];
  }

  for(int i = 0;i<c;i++){
    cin>>r[i];
  }

  priority_queue<lli,vector<lli>,greater<lli>> pq;

  sort(p.rbegin(),p.rend());
  sort(q.rbegin(),q.rend());
  sort(r.rbegin(),r.rend());

  for(int i = 0;i<x;i++){
    pq.push(p[i]);
  }
  for(int i = 0;i<y;i++){
    pq.push(q[i]);
  }

  lli ans = 0;

  for(int i = 0;i<c;i++){
    if(r[i]>pq.top()){
      pq.pop();
      ans+=r[i];
    }
  }

  while(!pq.empty()){
    ans+=pq.top();
    pq.pop();
  }

  cout<<ans;




}

 
 
 
 
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  //freopen("moobuzz.in","r",stdin);
  //freopen("moobuzz.out","w",stdout);
  int t = 1;
  //cin>>t;
  while(t--){
    solve();
  }
}
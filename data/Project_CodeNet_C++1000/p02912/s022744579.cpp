#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
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
  int n,m;
  cin>>n>>m;

  priority_queue<lli> pq;
  for(int i = 0;i<n;i++){
    lli a;
    cin>>a;
    pq.push(a);
  } 

  for(int i = 0;i<m;i++){
    lli val = pq.top();
    pq.pop();
    val = val/2;
    pq.push(val);
  }

  lli cost = 0;
  while(!pq.empty()){
    cost+=pq.top();
    pq.pop();
  }

  cout<<cost;

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
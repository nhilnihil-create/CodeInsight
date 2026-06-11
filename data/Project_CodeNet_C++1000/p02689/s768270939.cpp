#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll=long long;

int main(){
 int n,m,a,b,count=0;
 cin >> n >> m;
 vector<int> h(n);
 rep(i,n) cin >> h[i];
 vector<bool> ok(n,true);
 rep(i,m){
  cin >> a >> b;
  a--; b--;
  if(h[a]<=h[b]) ok[a]=false;
  if(h[b]<=h[a]) ok[b]=false;
 }
  rep(i,n) if(ok[i]) count++;
  cout << count << endl;
  return 0;
}

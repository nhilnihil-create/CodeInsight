#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;
const int ny[4] = {-1,1,0,0}, nx[4] = {0,0,-1,1};
int sy,sx,gy,gx;

int main(){
  int n; cin >> n;
  vector<P> x(n);
  
  for(int i = 0; i < n; i++){
    int a,b; cin >> a >> b;
    x[i] = P(a+b,a-b);
  }
  sort(x.begin(), x.end());
  int id = 0, mn = 999999999; 
  for(int i = 0; i < n; i++){
    if(mn > x[i].first){
      mn = x[i].first;
      id = i;
    }
  }
  int ans = 1;
  int left = x[id].first;
  for(int i = id+1; i < n; i++){
    int right = x[i].second;
    if(left > right) continue;
    ans++;
    left = x[i].first;
  }
  cout << ans << endl;
  return 0;
}

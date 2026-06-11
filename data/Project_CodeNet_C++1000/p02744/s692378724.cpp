#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int n;
  cin >> n;
  queue<string> q;
  q.push("a");
  while(!q.empty()){
    string now = q.front(); q.pop();
    if(now.size() == n){
      cout << now << endl;
      continue;
    }
    auto itr = max_element(now.begin(), now.end());
    int mx = *itr - 'a';
    rep(i, mx+2){
      char add = i + 'a';
      q.push(now + add);
    }
  }
  return 0;
}
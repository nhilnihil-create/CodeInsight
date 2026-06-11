#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;

int f(int p){
  if(p == 1){
    return 300000;
  }else if(p == 2){
    return 200000;
  }else if(p==3){
    return 100000;
  }
  return 0;
}

 
int main() {
  int x,y;
  cin >> x >> y;
  int ans = 0;
  if(x == 1 && y == 1){
    ans += 400000;
  }
  
  ans += f(x) + f(y);
  
  cout << ans << endl;
  
  return 0;
}


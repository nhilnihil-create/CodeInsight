#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n,x,y;
  cin >> n >> x >> y;
  vi ans(n,0);
  int diff;
  for(int i=1; i<=n-1; i++){
    for(int j=i+1; j<=n; j++){ 
      if(j-i > abs(x-i) + 1 + abs(y-j)) diff = abs(x-i) + 1 + abs(y-j);
      else diff = j-i;
      ans[diff] ++;
    }
   
  }
  for(int i=1; i<n; i++) cout << ans[i] << endl;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n,k;
  cin >> n >> k;
  int m = n-1;
  int cnt = (n-2)*(n-1)/2;
  if(cnt < k){
    cout << -1 << endl;
    return 0;
  }
  vector<vector<bool>>data(n,vector<bool>(n,false));
  rep(i,1,n){
    data[0][i] = true;
    data[i][0] = true;
  }
  rep(i,1,n){
    if(cnt == k) break;
    rep(j,1,n){
      if(cnt == k) break;
      if(i == j) continue;
      if(!data[i][j]){
        cnt--;
        m++;
        data[i][j] = true;
        data[j][i] = true;
      }
    }
  }
  cout << m << endl;
  rep(i,0,n){
    rep(j,0,i){
      if(data[i][j]) cout << i+1 << " " << j+1 << endl;
    }
  }
}
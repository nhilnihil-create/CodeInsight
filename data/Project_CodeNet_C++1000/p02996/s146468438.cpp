#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
int mod = 1000000007;
long long dp[100005];

int main() {
  vector<pair<int, int>> g;
  long long n;
  cin >> n;
  int a,b;
  for(int i =0;i<n;i++){
    cin >> a >> b;
    g.push_back({b,a});
  }
  sort(g.begin(), g.end());
  
  long long sa,sb;
  sa = 0;
  sb = 0;
  string flg = "Yes";
  for(int i = 0;i<n;i++){
    sa += g[i].second;
    sb = g[i].first;
    
    if(sa > sb){
      flg = "No";
      break;
    }
  }
  
  cout << flg << endl;
}

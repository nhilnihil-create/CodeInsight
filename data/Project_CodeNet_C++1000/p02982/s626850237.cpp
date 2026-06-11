#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
int n,d;
cin >> n >> d;
vector<vector<int>> a(n,vector<int>(d));
rep(i,n){
  rep(j,d) cin >> a.at(i).at(j);
}
int ans = 0;
rep(i,n){
  rep(j,i){
    int dis = 0;
    rep(k,d){
      dis += (a.at(i).at(k) - a.at(j).at(k))*(a.at(i).at(k) - a.at(j).at(k));
    }
    double s = sqrt(dis);
    int t = s/1;
    if(t == s) ans++;
  }
}
cout << ans << endl;
}
  

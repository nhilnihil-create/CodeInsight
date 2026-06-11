#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
const ll INF = 1001001001;

int main(){
  int n;
  cin >> n;
  vector<int> X(n);
  rep(i,n)cin >> X[i];
  int MIN = INF;
  for(int j = 1; j<101;j++){
    int cnt = 0;
    rep(i,n){
      cnt += pow(X[i]-j,2);
    }
    MIN = min(MIN,cnt);
  }
  cout << MIN << endl;
}

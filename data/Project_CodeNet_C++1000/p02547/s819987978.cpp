#include <bits/stdc++.h>
#include <vector>
#include <string.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
//#define INF 2e9
#define ALL(v) v.begin(), v.end()
 
using namespace std;
typedef long long ll;

int main(){
  int n;
  bool result=false;
  cin >> n;
  vector <vector <int>> D(n,vector<int>(2));
  rep(i,n){
    cin >> D[i][0] >> D[i][1];
  }
  rep(i,n-2){
    if(D[i][0]==D[i][1]&&D[i+1][0]==D[i+1][1]&&D[i+2][0]==D[i+2][1]){
      result = true;
    }
  }
  if(result) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
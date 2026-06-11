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
  int res = 0;
  bool result = false;
  cin >> n;
  int D1,D2;
  rep(i,n){
    cin >> D1 >> D2;
    if(D1 == D2) res += 1;
    else res = 0; 
    if(res == 3){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
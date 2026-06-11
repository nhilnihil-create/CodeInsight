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
  int x,ans=0;
  rep(i,5){
    cin >> x;
    if(x==0){
      ans=i+1;
    }
  }
  cout << ans;
  return 0;
}
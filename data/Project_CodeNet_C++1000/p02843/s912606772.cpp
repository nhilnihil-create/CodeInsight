#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

bool dp[1000100];
int main(){
  int x;
  cin >> x;
  dp[0] = true; 
  rep(i,x+1){
    rep(j,6){
      if (i-100-j >= 0 && dp[i-100-j]) dp[i] = true;
    }
  }
  if (dp[x]) cout << 1 << endl;
  else cout << 0 << endl;

  

}

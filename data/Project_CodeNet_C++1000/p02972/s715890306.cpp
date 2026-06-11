#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int main(){
  int n;
  cin >> n;
  vector<int> v(n+1);
  rep(i,n+1) {
    if (i == 0) continue;
    cin >> v[i];
  } 
  vector<int> ans(n+1);

  int len = v.size();
  int cnt = 0;
  for (int i = len-1;i > 0;i--){
    if (i*2 > len-1){
      ans[i] = v[i];
      if (ans[i] == 1) cnt++;
      //cout << i << ":" << "skip" << endl;
    }
    else{
      //cout << i << ":" << "do" << endl;
      int now = i + i;
      int cnow = i;
      int sum = 0;
      while(now <= len-1){
        sum += ans[now];
        now += cnow; 
      }
      if (sum%2 == 1 && v[cnow] == 0) ans[cnow] = 1,cnt++;
      else if (sum%2 == 1 && v[cnow] == 1) ans[cnow] = 0;
      else if (sum%2 == 0 && v[cnow] == 0) ans[cnow] = 0;
      else ans[cnow] = 1,cnt++; 
    }
  }
  cout << cnt << endl;
  if (cnt > 0){
    rep(i,n+1){
      if (i == 0) continue;
      if (ans[i] == 1){
        cout << i << " ";
      }
    }
    cout << endl;
  }


    
  return 0;
}

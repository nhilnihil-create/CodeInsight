#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int inf=100100100;
int main() {
  int h,n;
  cin >> h >> n;
  vector<int> a(n),b(n);
  for(int i=0;i<n;i++){
    cin >> a.at(i) >> b.at(i);
  }
  
  vector<int> dp(h+1,inf);
  dp.at(0) = 0;
  
  for(int i=0;i<n;i++){
    for(int j=0;j<=h;j++){
      int tmp = min(h,j+a.at(i));
      dp.at(tmp) = min(dp.at(tmp),dp.at(j)+b.at(i));
    }
  }
  
  cout << dp.at(h) << endl;
  
  return(0);
}
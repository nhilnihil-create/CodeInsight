#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <climits>
#include <utility>
typedef long long ll;
using namespace std;

int main(void){
  int n, i;
  string c;
  cin >> n >> c;

  vector<int> left, right;
  left.resize(n+1);
  right.resize(n+1);

  left[0] = 0;
  for(i=1;i<=n;i++){
    left[i] = left[i-1] + int(c[i-1]=='W');
  }

  right[n] = 0;
  for(i=n-1;i>=0;i--){
    right[i] = right[i+1] + int(c[i]=='R');
  }

  int ans = n;
  for(i=0;i<=n;i++){
    if(ans>max(left[i],right[i])){
      ans = max(left[i],right[i]);
    }
  }

  cout << ans << endl;

  return 0;
}

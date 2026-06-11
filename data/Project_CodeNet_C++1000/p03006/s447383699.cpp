#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
int main(){
  int n = 0;
  cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for(int i = 0;i < n;i++)cin >> x[i] >> y[i];
  int res = 0;
  map<pair<int,int>,int> count;
  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      if(i == j)continue;
      count[make_pair(x[j] - x[i],y[i] - y[j])]++;
    }
  }
  for(auto& item:count)res = max(res,item.second);
  cout << n - res << endl;
  return 0;
}
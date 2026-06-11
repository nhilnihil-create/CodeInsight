#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
using namespace std;
typedef long long ll;
int main(){
  int n = 0;
  cin >> n;
  vector<int> num(n);
  for(int i = 0;i < n;i++)cin >> num[i];
  int res = 0;
  for(int i = 0;i < n;i++)res ^= num[i];
  if(res == 0)cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
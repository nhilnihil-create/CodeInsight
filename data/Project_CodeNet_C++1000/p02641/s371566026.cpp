#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
  int x, n;
  cin >> x >> n;
  vector<int> nums;
  for (int i=0; i< n; i++) {
    int a;
    cin >> a;
    nums.push_back(a);
  }
  sort(nums.begin(), nums.end());

  auto center = find(nums.begin(), nums.end(), x);
  if (center == nums.end()) {
    // if x not found
    cout << x << endl;
    return 0;
  }

  int forward = 101;
  int backward = 101;

  int before = x;
  for (auto itr = center - 1; itr >= nums.begin(); itr--) {
    if (*itr != --before) {
      forward = before;
      break;
    }
  }
  if (forward == 101) {
    forward = before - 1;
  }

  before = x;

  for (auto itr = center + 1; itr < nums.end(); itr++) {
    if (*itr != ++before) {
      backward = before;
      break;
    }
  }

  if (backward == 101) {
    backward = before +1 ;
  }

  int ans = abs(forward-x) <= abs(backward-x) ?forward  : backward;
  cout << ans << endl;
}


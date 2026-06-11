#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define MAX 1000001
int n;
vector<int> nums;
bool canDiv[MAX] = {};
void eratos() {
  int before = 0;
  for (int i = 0; i<n;i++) {
    int base = nums[i];
    if (before == base) {
      canDiv[before] = true;
    }
    if (canDiv[base]) {
      continue;
    }
    for (int val = base*2; val < MAX; val+=base) {
      canDiv[val] = true;
    }
    before = base;
  }
}

int main(){
  cin >> n;
  int cnt = 0;
  for (int i=0; i<n;i++) {
    int a;
    cin >> a;
    nums.push_back(a);
  }
  sort(nums.begin(), nums.end());
  eratos();
  for (int i=0; i<n;i++) {
    if (!canDiv[nums[i]]) {
      cnt++;
    }
  }
  cout << cnt << endl;
}
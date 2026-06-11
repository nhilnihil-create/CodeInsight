#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

#ifdef _DEBUG
#define ASSERT(x) cassert(x)
#define DLOG(x) cout << #x " " << x << endl;
#else
#define ASSERT(x)
#define DLOG(x)
#endif

using namespace std;

int insertSort(vector<int>& arr, int step) {
  int cnt = 0;
  for (auto i = step; i < arr.size(); ++i) {
    auto j = i - step;
    auto v = arr[i];
    for (; j >= 0 && arr[j] > v; j -= step) {
      arr[j + step] = arr[j];
      ++cnt;
    }
    arr[j + step] = v;
  }
  return cnt;
}

vector<int> makeSteps(int n) {
  vector<int> steps;
  for (int v = 1; v <= n; v *= 4) {
    steps.push_back(v);
  }
  sort(steps.begin(), steps.end(), greater<int>()); 
  return steps;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr;
  arr.reserve(n);
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    arr.push_back(t);
  }
  auto steps = makeSteps(arr.size());
  int cnt = 0;
  for (auto step : steps) {
    cnt += insertSort(arr, step);
  }
  cout << steps.size() << endl;
  bool first = true;
  for (auto step : steps) {
    if (!first) {
      cout << " ";
    }
    first = false;
    cout << step;
  }
  cout << endl << cnt << endl;
  for (auto v : arr) {
    cout << v << endl;
  }
}


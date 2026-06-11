#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int N;
  vector<int> d;
  cin >> N;
  for (int i = 0; i < N; i++){
    int tmp;
    cin >> tmp;
    d.push_back(tmp);
  }
  sort(d.begin(), d.end());

  int h = N / 2, ans;
  ans = d[h] - d[h-1];
  printf("%d\n", ans);
}

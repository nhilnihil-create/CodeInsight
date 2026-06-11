#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <numeric>
#include <cfloat>
#include <iomanip>
using namespace std;
int main(){
  int N;
  cin >> N;
  long long ans = 0;
  for(int i = 1; i <= N; i++){
    ans += (long long) (i) * (long long) (i + 1) / 2;
  }

  for(int i = 0; i < N - 1; i++){
    int u;
    int v;
    cin >> u >> v;
    ans -= (long long) min(u, v) * (long long)(N - max(u, v) + 1);
  }
  cout << ans << endl;
  return 0;
}

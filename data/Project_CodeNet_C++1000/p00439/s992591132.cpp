#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <limits>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <complex>

using namespace std;

//define
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define dump(x)  cerr << #x << " = " << (x) << endl;

#define INF (INT_MAX/3)
#define PI (2*acos(0.0))
#define EPS (1e-8)

typedef long long ll;
typedef unsigned long long ull;

int main(){
  ios_base::sync_with_stdio(0);
  int n, k;
  while(cin >> n >> k, n || k){
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int sum = 0, ans = 0;
    for(int i = 0; i < k; i++) sum += arr[i];
    ans = sum;
    for(int i = 1; i + k - 1 < n; i++){
      sum -= arr[i-1];
      sum += arr[i+k-1];
      ans = max(ans, sum);
    }
    cout << ans << endl;
  }
  return 0;
}
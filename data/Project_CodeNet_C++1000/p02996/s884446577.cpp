#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

int main(){
  int n;
  const int max_n = 2 * 1e5;
  int a[max_n + 1], b[max_n + 1];
  pair<int, int> task[max_n + 1];
  cin >> n;
  for(int i = 0; i < n; i++) {
    int a,b;
    cin >> a >> b;
    task[i] = make_pair(b,a);
  }
  sort(task, task+n);
  // for(int i = 0; i < n; i++) cout << task[i].first << "," << task[i].second << endl;

  int now = 0;
  string ans = "Yes";
  for(int i = 0; i < n; i++){
    now += task[i].second;
    if(now > task[i].first) ans = "No";
  }
  cout << ans << endl;

  return 0;
}
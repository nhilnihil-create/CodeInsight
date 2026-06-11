#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()

int main(){
  int n;
  cin >> n;
  int weight[n];
  int sum = 0, mn = INT_MAX;
  for(int i = 0; i < n; i++) {cin >> weight[i]; sum += weight[i];}
  int cur = 0;
  for(int i = 0; i < n; i++) {cur += weight[i]; mn = min(mn, abs(cur - (sum - cur)));}
  cout << mn;
}
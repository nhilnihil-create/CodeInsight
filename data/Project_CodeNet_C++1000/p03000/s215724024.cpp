#include <bits/stdc++.h>
using namespace std;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define INF 1000000000
typedef long long ll;

int main(){
  int n, x, cnt = 1, sum = 0, j;
  cin >> n >> x;
  for(int i = 0; i < n; i++) {cin >> j; sum += j; if(sum<=x)cnt++;}
  cout << cnt;
}  
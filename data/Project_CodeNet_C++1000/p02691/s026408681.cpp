#include<bits/stdc++.h>
using namespace std;

#define dbg(a)  cerr << __LINE__ << ": " << #a << " = " << a << '\n'

typedef long long ll;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int n;  cin >> n;
  unordered_map<int, int> cnt1(n), cnt2(n);
  ll ans = 0;
  for (int i = 0; i < n; ++i){
    int ai; cin >> ai;
    int one = i-ai, two = i+ai;
    ans += cnt2[one] + cnt1[two];
    cnt1[one]++, cnt2[two]++;
  }
  cout << ans << "\n";
  return 0;
}
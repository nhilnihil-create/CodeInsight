#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

int main(){
  int n;
  const int max_n = 2 * 1e5;
  int a[max_n + 1];
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];

  bool ball[max_n + 1] = {};
  int cnt = 0;
  for(int i = n; i >= 1; i--){
    int sum = 0;
    int now = 2 * i;
    while(now <= n){
      sum += ball[now-1];
      now += i;
    }
    if(sum % 2 - a[i-1] != 0) {
      ball[i-1] = 1;
      cnt ++;
    }
  }

  cout << cnt << endl;
  for(int i = 0; i < n; i++){
    if(ball[i] == 0) continue;
    if(i == n - 1) cout << i + 1<< endl;
    else cout << i + 1 << " ";
  }
  
  

  return 0;
}
#include<bits/stdc++.h>
using namespace std;

const int INF = 1 << 12;

int main(){
  int N  ;
  cin >> N ;
  vector<int> W(N);
  for(int i = 0; i < N; i++) cin >> W[i];
  vector<int> XW(N + 1, 0);
  for(int i = 1; i <= N; i++) XW[i] = XW[i - 1] + W[i - 1];
  int ans = INF;
  for(int i = 1; i < N; i++) ans = min(ans, abs(XW[N] - 2 * XW[i]));
  
  cout << ans;
  
}
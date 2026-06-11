#include<bits/stdc++.h>
using namespace std;

int main(){
  long long int N ,ans = 0 ;
  string S ;
  cin >> N ;
  vector<int> d(N);
  for(int i = 0; i < N; i++) cin >> d[i];

  vector<long long int> e(N + 1);
  for(int i = 0; i < N ; i++) e[i + 1] = e[i] + d[i];
  for(int i = 0; i < N ; i++) ans += d[i] * (e[N] - e[i + 1]);
  cout << ans << endl;
}

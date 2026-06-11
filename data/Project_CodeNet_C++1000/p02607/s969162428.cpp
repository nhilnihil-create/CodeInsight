#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,ans = 0;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
    if (i % 2 == 0 && a.at(i) % 2 != 0) ans++;
  }
  cout << ans << endl;
}

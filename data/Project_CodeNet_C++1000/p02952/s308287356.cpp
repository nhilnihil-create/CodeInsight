#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll N; cin >> N;
  ll cnt = 0;
  for(ll i = 1; i <= N; i++) {
    string s = to_string(i);
    int j = s.size();
    if(j % 2 == 1) cnt++;
  }
  cout << cnt << endl;
}
#include <bits/stdc++.h>
#include <iomanip>
#include <algorithm>
#define ll long long
#include <unordered_map>
using namespace std;
 
int main() {
  ll N, cnt = 0, f, s;
  bool flag = 0;
  cin >> N;
  for(ll i = 0; i < N; i++) {
    cin >> f >> s;
    if(f == s) cnt++;
    else cnt = 0;
    if(cnt == 3) flag = 1;
  }
  if(flag == 1) cout << "Yes" << endl;
  else cout << "No" << endl;
}
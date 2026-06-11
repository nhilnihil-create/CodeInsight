#include <bits/stdc++.h>
#include <iomanip>
#include <algorithm>
#define ll long long
#include <unordered_map>
using namespace std;
 
int main() {
  ll N;
  cin >> N;
  for(ll i = 0; i <= N; i++) {
    if((long)(i * 1.08) == N) {
      cout << i << endl;
      break;
    }
    if(i == N) cout << ":(" << endl;
  }
}
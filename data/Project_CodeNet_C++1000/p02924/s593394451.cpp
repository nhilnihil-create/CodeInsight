#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

int main(){
  int n;
  cin >> n;

  long long sum = 0;
  for(int i = 1; i < n; i++){
    sum += i;
  }
  cout << sum << endl;

  return 0;
}
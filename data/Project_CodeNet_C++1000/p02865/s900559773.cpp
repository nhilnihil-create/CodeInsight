#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  (n%2 == 0) ? cout << n/2-1 << "\n" : cout << (int)n/2 << "\n";
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, l;
  cin >> n >> l;
  int sum = (l + l + n - 1) * n / 2;
  if(l>=0) cout << sum - l;
  else if(abs(l) < n) cout << sum;
  else cout << sum - (l + n - 1);
}
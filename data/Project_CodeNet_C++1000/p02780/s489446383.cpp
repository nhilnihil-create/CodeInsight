#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k;
  cin >> n >> k;
  vector<int> p(n);
  for (int i = 0;i < n;i++){
    cin >> p.at(i);
  }
  
  int q = 0;
  for (int i = 0;i < k;i++){
    q += p.at(i);
  }
  
  int x = n - k + 1;
  vector<long> s(x,q);

  for (int i = 1;i < x;i++){
    s.at(i) = s.at(i-1) - p.at(i-1) + p.at(i-1+k);
  }
  
  int a = 0;
  for (int i = 1;i < x;i++){
    if (s.at(a) < s.at(i)){
      a = i;
    }
  }
  
  double ans = (double)(s.at(a) + k) / 2;
  
  cout << fixed << setprecision(2);
  
  cout << ans << endl;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<double> a(n);
  double ans = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  for(int i = 0; i < n; i++){
    ans += (double)(1 / a[i]);
  }
  cout << fixed << setprecision(15) << (double)(1 / ans) << endl;
}
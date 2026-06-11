#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> x(n);
  for(int i = 0; i < n; i++){
    cin >> x[i];
  }
  long long ans = 1000000000000000;
  for(int i = 0; i <= 100; i++){
    long long tmp = 0;
    for(int j = 0; j < n; j++){
      tmp += abs(x[j] - i) * abs(x[j] - i);
    }
    ans = min(tmp, ans);
  }
  cout << ans << endl;
}

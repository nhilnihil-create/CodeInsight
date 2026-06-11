#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  long d;
  cin >> n >> d;

  vector<long> x(n);
  vector<long> y(n);

  long long tmp=0;
  int ans=0;
  for(int i=0;i<n;i++){
    cin >> x[i] >> y[i];
  }
  for(int i=0;i<n;i++){
    tmp = x[i]*x[i];
    tmp += y[i]*y[i];
    if(tmp<=d*d){
      // cout << tmp << " " << d*d << endl;
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}

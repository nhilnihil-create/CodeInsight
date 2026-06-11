#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k;
  cin >> n >> k;
  vector<double> p(n);
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    p.at(i) = (x+1)/2.0;
  }

  vector<double> sum(n+1,0);
  sum.at(0) = 0;
  for(int i=0;i<n;i++){
    sum.at(i+1) = sum.at(i) + p.at(i);
  }
  
  /*
  for(int i=0;i<n;i++){
    cout << sum.at(i) << endl;
  }
  */
  
  double ans=0;
  for(int i=0;i<n-k+1;i++){
    //cout << i << " " << i+k << endl;
    if(ans < sum.at(i+k)-sum.at(i)){
      ans = sum.at(i+k)-sum.at(i);
    }
  }
  cout << fixed << setprecision(10) << ans << endl;
  return(0);
}
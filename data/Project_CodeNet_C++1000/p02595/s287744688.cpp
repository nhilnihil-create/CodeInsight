#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  long long d;
  cin >> n >> d;
  vector<long long> x(n),y(n);
  for(int i=0;i<n;i++){
    cin >> x.at(i) >> y.at(i);
  }
  int ans = 0;
  long long d2 = d*d;
//  cout << d2 << endl;
  for(int i=0;i<n;i++){
    long long dis2 = x.at(i)*x.at(i)+y.at(i)*y.at(i);
//    cout << dis2 << endl;
    if(d2 >= dis2)
      ans++;
  }
  cout << ans << endl;
}
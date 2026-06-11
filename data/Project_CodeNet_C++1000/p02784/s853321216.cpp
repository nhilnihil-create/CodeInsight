#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1000000007;



int main() {
  ll h,n;
  cin >> h >> n;
  vector<int> a(n);
  ll sum=0;
  for(int i=0;i<n;i++){
    cin >> a.at(i);
    sum+=a.at(i);
  }
  if(h>sum)
  cout << "No" << endl;
  else
  cout << "Yes" << endl;
}

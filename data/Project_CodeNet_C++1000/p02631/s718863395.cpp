#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1000000007;



int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  ll b=0;
  for(int i=0;i<n;i++){
    cin >> a.at(i);
    b^=a.at(i);
  }
  for(int i=0;i<n;i++){
    cout << (b^a.at(i)) << " ";
  }
  cout << endl;
}
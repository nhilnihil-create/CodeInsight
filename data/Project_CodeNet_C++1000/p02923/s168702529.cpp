#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1000000007;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);
  int c=0;
  for(int i=0;i<n;i++){
    cin >> a.at(i);
  }
  for(int i=0;i<n-1;i++){
    if(a.at(i)>=a.at(i+1)){
      b.at(c)++;
    }
    else{
      c=i+1;
    } 
  }
  sort(b.begin(), b.end());
  cout << b.at(n-1) << endl;
}

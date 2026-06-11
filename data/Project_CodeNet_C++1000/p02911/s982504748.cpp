#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  ll n,k,q;
  cin >> n >> k >> q;
  vector<int> a(n);
  for(ll i=0;i<q;i++){
    int b;
    cin >> b;
    a.at(b-1)++;
  }
  for(int i=0;i<n;i++){
    if(k-q+a.at(i)>0)
    cout << "Yes" << endl;
    else
    cout << "No" << endl;
  }
}


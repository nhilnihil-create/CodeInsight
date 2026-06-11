#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll n,a,b;
  cin >> n >> a >> b;
  if((a+b)%2) cout << min(2*n-a-b+1,a+b-1)/2 << endl;
  else cout << (b-a)/2 << endl;
}
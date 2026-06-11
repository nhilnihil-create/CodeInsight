#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  ll n,a,b;
  cin >> n >> a >> b;
  if((b-a)%2==0)
    cout << (b-a)/2 << endl;
  else if(n-a>b-1)
    cout << a+(b-a-1)/2 << endl;
  else
    cout << n-b+1+(b-a-1)/2 << endl;
}

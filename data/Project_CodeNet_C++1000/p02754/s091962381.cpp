#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
  ll n, a, b;
  cin >> n >> a >> b;
  
  ll x = n / (a + b);
  ll y = n % (a + b);
  ll z = min(a, y);
  
  cout << x * a + z << endl;
} 
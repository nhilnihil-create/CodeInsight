#include<bits/stdc++.h>
using namespace std;

int main(){
  long long a,b;
  cin >> a >> b;
  long long p = a * b;
  long long g = gcd(a,b);
  long long ans = p / g;
  cout << ans << endl;
}
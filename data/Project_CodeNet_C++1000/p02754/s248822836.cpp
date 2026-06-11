#include <bits/stdc++.h>
using namespace std;
 
int main() {
 long long n,a,b;
  cin >> n >> a >>b;
long long ans=n / (a+b);
  ans *=a;
  long long r= n % (a+b);
 
  ans += min(r,a);
  cout << ans <<endl;
}
  

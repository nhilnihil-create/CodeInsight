#include <bits/stdc++.h>
using namespace std;
 
long long LCM(int a, int b) {
    return a * 1ll * b / __gcd(a, b);
}
 
int main() {
    int n, m;
    cin >> n >> m;
    long long lcm = 1;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        lcm = LCM(lcm, a[i] / 2);
    }
   for (int i = 0; i < n; ++i) {
        if ((2 * lcm / a[i]) % 2 == 0) {
            return cout << 0, 0;
        }
    }
  int ans=0;
  long long c=lcm;
  int p=1;
  while(lcm<=m){
  	ans++;
  	p=p+2;
  	lcm=p*c;
  	
  }
  cout<<ans;
}
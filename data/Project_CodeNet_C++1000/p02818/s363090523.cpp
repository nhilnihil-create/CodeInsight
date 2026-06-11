#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
using ll = long long;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   ll a, b, k;
   cin >> a >> b >> k;
   if (a >= k){
      cout << a-k << endl;
      cout << b << endl;
   }
   else if (a+b >= k){
      cout << 0 << endl;
      cout << a+b-k << endl;
   }
   else{
      cout << 0 << endl;
      cout << 0 << endl;
   }
   
}
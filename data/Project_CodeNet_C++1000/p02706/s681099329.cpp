#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; ++i) // マクロ
using namespace std; // stdの省略
using pii = pair<int, int>; // pairの略記
using ll = long long; // long longの略記


int main(void) {
   
   int n, m;
   cin >> n >> m;
   
   vector<int> a(m);
   int sum = 0;
   rep(i,m) {
       cin >> a[i];
       sum += a[i];
   }
   
   int ans = -1;
   if (n>=sum) ans = n - sum;
   cout << ans << endl;
   
   return 0;
}
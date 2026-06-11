#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; ++i) // マクロ
using namespace std; // stdの省略
using pii = pair<int, int>; // pairの略記
using ll = long long; // long longの略記


int main(void) {
   
   int n;
   cin >> n;

   int A;
   vector<int> a(n);
   rep(i,n-1) {
       cin >> A;
       A--;
       a[A]++;
   }

   rep(i,n) cout << a[i] << endl;
   
   return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep2(i, a, b) for(int i = (a); i < (b); i++)
typedef long long ll;

int main() {
   int n, m;
   cin >> n >> m;
   int a[n];

   double sum = 0;
   rep (i, n) {
       cin >> a[i];
       sum += a[i];
   }

   int count = 0;
   rep (i, n) {
       if (a[i] >= (sum / (4 * m))) count++;
   }

   if (count >= m) cout << "Yes" << endl;
   else cout << "No" << endl;
}
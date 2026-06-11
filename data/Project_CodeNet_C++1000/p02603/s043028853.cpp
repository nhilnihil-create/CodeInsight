#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 85;

int main() {
   int n;
   cin >> n;
   vector <int> a(n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   ll cash = 1000;
   for(int i=1; i<n; i++) {
      if(a[i] > a[i-1]) {
         ll x = cash / a[i-1];
         cash += x * (a[i] - a[i-1]);
      }
   }
   cout << cash << endl;
}

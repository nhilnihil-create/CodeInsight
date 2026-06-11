#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, x;
bool a[105];
int main() {
   cin >> x >> n;
   for (int i=0; i<n; i++) {
       int t; cin >> t; a[t]=1;
   }
   int d=0;
   while (true) {
       if (!a[x-d]) {cout << x-d; return 0;}
       if (!a[x+d]) {cout << x+d; return 0;}
       d++;
   }
}
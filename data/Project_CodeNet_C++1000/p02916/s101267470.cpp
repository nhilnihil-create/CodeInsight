#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, a[25], b[25], c[25], ans;
int main() {
   cin >> n;
   for (int i=0; i<n; i++) {cin >> a[i]; a[i]--;}
   for (int i=0; i<n; i++) cin >> b[i];
   for (int i=0; i<n-1; i++) cin >> c[i];
   
   for (int i=0; i<n; i++) {
       ans+=b[a[i]];
       if (i>0) {
           if (a[i]==a[i-1]+1) ans+=c[a[i-1]];
       }
   }
   cout << ans;
}
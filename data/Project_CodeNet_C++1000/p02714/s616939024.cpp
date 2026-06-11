#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
using ll = long long;
const ll MOD = 1000000007;//998244353;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   ll NumR=0,NumG=0,NumB=0;
   int n; cin >> n;
   string s; cin >> s;
   rep(i,n)
   {
      switch (s[i]){
      case 'R': NumR++; break;
      case 'G': NumG++; break;
      case 'B': NumB++; break;
      }
   }
   ll ans = NumR*NumG*NumB;
   for (int i = 0; i < n; i++){
      for (int j = 0; i+2*j+2 < n; j++)
      {
         char si=s[i], sj=s[i+j+1], sk=s[i+2*j+2];
         if (si!=sj&&si!=sk&&sj!=sk){
            ans--;
         }
      }
   }
   cout << ans << endl;
}
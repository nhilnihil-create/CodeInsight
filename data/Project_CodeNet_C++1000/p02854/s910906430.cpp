#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i,s,n) for(int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(){
   int n;
   cin >> n;
   ll a[n];
   ll max_size = 0;
   rep(i, n) { 
       cin >> a[i];
       max_size += a[i];
   }
   ll min_size = max_size, sum = 0;
   rep(i, n) { 
       sum += a[i];
       min_size = min(min_size, abs(sum - (max_size - sum)));
   }
   cout << min_size << endl;
   return 0;
}
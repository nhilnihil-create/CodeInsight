#include <iostream>
#include <string>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

int main(void){
   int n;
   cin >> n;

   vector<ll> a(n);
   vector<ll> sums(n + 1);
   sums.at(0) = 0;
   ll S = 0;
   for (int i = 0; i < n; i++){
      cin >> a.at(i);
      sums.at(i+1) = sums.at(i)+a.at(i);
      S += a.at(i);
   }
   ll ans = 20202020202345;

   for (int i = 0; i <= n-1;i++){
      ll sum_r = sums.at(n) - sums.at(i);
      ans = min(ans, abs(sum_r - sums.at(i)));
   }
   cout << ans << endl;

   return 0;
}
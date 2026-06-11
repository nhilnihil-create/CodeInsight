#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for (int i=0; i<n; i++) {
       cin >> a[i];
   }
   sort(a.begin(), a.end());
   float ans = a[0] / (pow(2, n-1));
   for (int i=1; i<n; i++) {
       ans += a[i] / (pow(2, n-i));
   }
   cout << ans << '\n';
   
   return 0;
}
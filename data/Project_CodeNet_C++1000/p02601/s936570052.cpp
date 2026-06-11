#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+5;

int main() {
   int x, y, z, k;
   cin >> x >> y >> z >> k;

   while(k && y <= x) k--, y <<= 1;
   while(k && z <= y) k--, z <<= 1;

   if(x < y && y < z) puts("Yes");
   else puts("No");
}

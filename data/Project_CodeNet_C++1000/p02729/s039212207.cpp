#include <bits/stdc++.h>
using namespace std;

int C(int n) {
   return (n * (n - 1)) / 2;
}
int main() {

   ios_base::sync_with_stdio(0);
   cin.tie(0);

   int n, m;
   cin >> n >> m;
   cout << C(n) + C(m) << endl;
   return 0;
}
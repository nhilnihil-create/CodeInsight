#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;

int main() {
  int n,k,q;
   cin >> n >> k >> q;

   std::vector<int> vec(n,k);
   rep(i,q) {
     int x;
     cin >> x;
     x--;
     vec.at(x)++;
   }
   rep(i,n) {
     if (vec.at(i)-q <= 0) cout << "No" << endl;
     else cout << "Yes" << endl;
   }
}

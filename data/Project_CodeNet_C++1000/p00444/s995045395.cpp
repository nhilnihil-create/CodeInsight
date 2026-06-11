#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define pq priority_queue
#define debug(x) cerr << #x << ": " << x << endl;
#define line() cerr << "---------------" << endl;

int main() {
   int n;
   while (cin >> n, n) {
      int o = 1000 - n;
      int cnt = 0;
      while (o != 0) {
         if (o >= 500) {
            o -= 500;
         } else if (o >= 100) {
            o -= 100;
         } else if (o >= 50) {
            o -= 50;
         } else if (o >= 10) {
            o -= 10;
         } else if (o >= 5) {
            o -= 5;
         } else if (o >= 1) {
            o -= 1;
         }
         cnt++;
      }
      cout << cnt << endl;
   }

   return 0;
}

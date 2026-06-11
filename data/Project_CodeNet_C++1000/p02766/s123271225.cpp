#include <bits/stdc++.h>
using namespace std;

int main() {
   long N, K;
   cin >> N >> K;
   long a = 1, count = 0;

   while(a <= N) {
      a *= K;
      count++;
   }
   if (count < 1) count++;
   cout << count << endl;
}
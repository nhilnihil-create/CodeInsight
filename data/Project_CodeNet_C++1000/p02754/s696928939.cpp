#include <bits/stdc++.h>
using namespace std;

int main() {
   long long N, A, B;
   cin >> N >> A >> B;
   long long a = (N / (A + B));

   if(a <= 0) {
      cout << min(N, A) << endl;
      return 0;
   }
   else if(a > 0) {
      long long ans = a * A;
      N = (N % (A + B));
      ans += min(A, N);
      cout << ans << endl;
   }
}
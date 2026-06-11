#include <bits/stdc++.h>

 using namespace std;
 typedef long long ll;

 int main() {
   int N, ans = 0;
   string X;

   cin >> N;

   vector<string> s(N);
   vector<int> t(N);
   for (int i = 0; i < N; i++) cin >> s.at(i) >> t.at(i);
   cin >> X;

   for (int i = 0; i < N - 1; i++) {
     if (X == s.at(i)) {
       for (int j = i + 1; j < N; j++) {
         ans += t.at(j);
       }
     }
   }
   cout << ans << endl;
 }

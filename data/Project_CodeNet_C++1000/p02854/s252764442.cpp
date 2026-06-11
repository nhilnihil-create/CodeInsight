#include <bits/stdc++.h>

 using namespace std;
 typedef long long ll;

 int main() {
   int N;

   cin >> N;

   vector<int> A(N);
   for (int i = 0; i < N; i++) cin >> A.at(i);

   vector<ll> A_toi(N);
   vector<ll> A_fromi(N);

   A_toi.at(0) = A.at(0);
   for (int i = 1; i < N; i++) {
     A_toi.at(i) = A_toi.at(i - 1) + A.at(i);
   }

   A_fromi.at(N - 1) = A.at(N - 1);
   for (int i = N - 2; i >= 0; i--) {
     A_fromi.at(i) = A_fromi.at(i + 1) + A.at(i);
   }

   ll min_gap = 2020202020;

   for (int i = 0; i < N - 1; i++) {
     min_gap = min(min_gap, abs(A_toi.at(i) - A_fromi.at(i + 1)));
   }

   cout << min_gap << endl;
 }

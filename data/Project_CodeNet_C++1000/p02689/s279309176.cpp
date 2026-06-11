#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> vec(N), H(N,0);
   for (int i = 0; i < N; i++) {
     cin >> vec.at(i);
   }
   for (int j = 0; j < M; j++) {
     int A = 0, B = 0;
     cin >> A >> B;
     int a = A - 1;
     int b = B - 1;
     if (vec.at(a) == vec.at(b)){
       H.at(a) ++;
       H.at(b) ++;
     }
       else if (vec.at(a) > vec.at(b))
         H.at(b) ++;
       else
         H.at(a) ++;
   }
  int x = 0;
   for (int i = 0; i < N; i++) {
     if (H.at(i) == 0)
       x ++;
   }
  cout << x << endl;
}
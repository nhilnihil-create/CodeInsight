#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
   for (int i = 0; i < N; i++) {
     cin >> vec.at(i);
   }
  sort(vec.begin(), vec.end());
  int a = vec.at(0);
  int b = vec.at(N-1);
  vector<int> P(b-a+1,0);
  int y = 0;
   for (int i = a; i < b+1; i++) {
     int x = 0;
      for (int j = 0; j < N; j++) {
        int t = (vec.at(j) - i) * (vec.at(j) - i);
        x += t;
      }
     P.at(y) = x;
     y ++;
   }
  sort(P.begin(), P.end());
  cout << P.at(0) << endl;
}
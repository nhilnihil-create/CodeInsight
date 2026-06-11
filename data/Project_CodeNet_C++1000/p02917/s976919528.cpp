#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> vec(N-1);
   for (int i = 0; i < N-1; i++) {
     cin >> vec.at(i);
   }
  int x = vec.at(0) + vec.at(N-2);
   for (int i = 0; i < N-2; i++) {
     x += min (vec.at(i), vec.at(i+1));
   }
  cout << x << endl;
}
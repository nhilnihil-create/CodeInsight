#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
   for (int i = 0; i < N; i++) {
     cin >> vec.at(i);
   }
  int a = 1;
  int x = 0;
   for (int i = 0; i < N; i++) {
     if (vec.at(i) != a){
       x ++;
     }
     else {
       a ++;
     }
   }
  if (x == N)
    x = -1;    
  cout << x << endl;     
}
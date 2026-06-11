#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
 
  vector<int> k(N);
  for (int i = 0; i < N; i++) {
  cin >> k.at(i);
}
  sort(k.begin(), k.end());
  int a = 0;
  for (int i = 0; i < N-2; i++){
   for (int j = 1; j < N-1; j++){
     for (int l = 2; l < N; l++){
       if(k.at(i) < k.at(j) && k.at(j) < k.at(l)  &&
          k.at(i) + k.at(j) > k.at(l) )
       {a++;}
     }}}
  
  cout << a << endl;
}
       
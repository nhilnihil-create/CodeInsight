#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  bool l=true;
  vector <int>vec(N);
  for (int X=0; X<N; X++){
    cin >> vec.at(X);
    if (vec.at(X)%2==0){
      if (vec.at(X)%3!=0 && vec.at(X)%5!=0){
        l=false;
      }
    }
  }
  if (l==false){
    cout << "DENIED" << endl;
  }
  else {
    cout << "APPROVED" << endl;
  }
}
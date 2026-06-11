#include <bits/stdc++.h>
using namespace std;


int main() {
  int N;
  cin >> N;
  
  vector<int> Xn(N);
  for (int i=0; i<N ;i++){
    cin >> Xn.at(i);
  }
  
  int sum = 10000000;
  
  for (int i=1; i<101;i++){
  int neko = 0;
   for (int j=0; j<N ;j++){
     neko = neko + (Xn.at(j)-i)*(Xn.at(j)-i);
   }
   if (neko < sum){
     sum = neko;
   }
  }
  cout << sum << endl;
  
  return 0;
}


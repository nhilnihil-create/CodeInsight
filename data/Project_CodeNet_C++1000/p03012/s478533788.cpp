#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  
  for (int i = 0; i < N; i++) {
    cin >> vec.at(i);
  }
    int goukei=0;
   for (int i = 0; i < N; i++) {
    goukei += vec.at(i);}
  
  int SA=0, SB=0, s=0;
   for (int i = 0; i < N; i++) {
     SA += vec.at(i);
     SB = goukei - SA;
     if(SA > SB){
       int p = SA - SB;
        if(p < s)
          s = p;
       else
         break;
     }
     else
       s = SB - SA;
   }
  cout << s << endl;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >>N;
   for (int i = 1; i <10; i++) {
   if(N/i<10 && N%i==0){
   cout << "Yes";
   return 0;
    }
   }
  cout << "No";
 }

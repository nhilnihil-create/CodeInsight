#include <bits/stdc++.h>
using namespace std;

int main() {
 int N,A = 0;
 cin >> N;
 for(int i=1; i<=N; i++){
   if (i>0 && i<10 ){
     A++;
   }
   else if (i>99 && i<1000){
     A++;
   }
   else if (i>9999 && i<100000){
     A++;
   }
 }
   cout << A << endl;
}

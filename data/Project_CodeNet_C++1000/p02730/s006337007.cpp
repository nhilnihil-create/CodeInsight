#include <bits/stdc++.h>
using namespace std;


int main(void){
   string S;
   cin >> S;
   
   bool kaibun1=true;
   bool kaibun2=true;
   bool kaibun3=true;
   int N=S.size();
   
   
   for (int i=0;i<N;i++) {
       if (S[i] != S[N-1-i]) {
           kaibun1 = false;
           break;
       }
   }
   
   for (int i=0;i<(N-1)/2;i++) {
       if (S[i] != S[(N-1)/2-1-i]) {
           kaibun2 = false;
           break;
       }
   }
   
   for (int i=0;i<(N-1)/2;i++) {
       if (S[(N+3)/2-1+i] != S[N-1-i]) {
           kaibun3 = false;
           break;
       }
   }
   if (kaibun1==true&&kaibun2==true&&kaibun3==true) {
       cout << "Yes" << endl;
   }
   else {
       cout << "No" << endl;
   }
   
}



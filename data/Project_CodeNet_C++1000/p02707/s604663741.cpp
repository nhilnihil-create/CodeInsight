#include <bits/stdc++.h>
using namespace std;
int main(void){
   int N,A;
   cin >> N;
   map<int,int> data;
   for (int i=0;i<N;i++) {
       data[i]=0;
   } 
   for (int i=0;i<N-1;i++) {
       cin >> A;
       data[A-1]++;
   }
   for (int i=0;i<N;i++) {
       cout << data[i] << endl;
   }
} 

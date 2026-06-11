#include <bits/stdc++.h>
using namespace std;

int main(void){
   int N,M;
   cin >> N >> M;
   int count=0;
   int sum=0;
   vector<int> A(N);
   for (int i=0;i<N;i++) {
       cin >> A[i];
       sum+=A[i];
   }
   
   for (int i=0;i<N;i++) {
       if (A[i]>= (sum+4*M-1)/(4*M)){
           count++;
       }
   }
   
   if(count<M) {
       cout << "No" << endl;
   }
   else {
       cout << "Yes" << endl;
   }
   
}



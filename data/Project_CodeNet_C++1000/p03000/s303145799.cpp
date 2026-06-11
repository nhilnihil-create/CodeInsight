#include <bits/stdc++.h>
using namespace std;

int main(void){
    
   int N,X,sum=0;
   cin >> N >> X;
   int L[N];
   
   for(int i=0;i<N;i++) cin >> L[i];
   
   int D = 0;
   for(int i=0;i<N+1;i++){
       if(D <= X) sum++;
       D = D + L[i];
   }
   cout << sum <<endl;
}
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <string>
#include<iomanip>
#include<limits>
using namespace std;
int main(void){
   int N;
   cin>>N;
   int A[N],B[N],C[N];
   for(int i=0;i<N;i++){
       cin>>A[i];
   }
   for(int i=0;i<N;i++){
       cin>>B[i];
   }
   for(int i=0;i<N-1;i++){
       cin>>C[i];
   }
   int sum=0;
   for(int i=0;i<N;i++){
       sum+=B[A[i]-1];
       if(A[i]==A[i-1]+1 & i-1>=0){
           sum+=C[A[i-1]-1];
       }
   }
   cout<<sum<<endl;
}

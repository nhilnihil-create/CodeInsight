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
   int N,K;
   cin>>N>>K;
   int P[N];
   int count=0;
   for(int i=0;i<N;i++){
       cin>>P[i];
       if(P[i]>=K){
           count++;
       }
   }
   cout<<count<<endl;
}

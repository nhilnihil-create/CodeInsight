#include <bits/stdc++.h>
using namespace std;

int main(void){
   
   int N;
   double sum_A = 0,sum_B = 1;
   cin >> N;
   int data[N];
   for(int i=0;i<N;i++){
       cin >> data[i];
       sum_B *= data[i];
   }
   
   for(int i=0;i<N;i++){
       sum_A += (sum_B / data[i]);
   }
   printf("%.16f\n",1 /  (sum_A / sum_B));
}
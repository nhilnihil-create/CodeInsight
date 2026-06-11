#include<iostream>

using namespace std;

int main(){

   while(1){
      int N, M;
      cin>> N>> M;
      if(!(N||M)) break;

      int h[N], w[M];
      for(int i=0; i<N; i++) cin>> h[i];
      for(int i=0; i<M; i++) cin>> w[i];

      int p[1000*1500+1]={};
      for(int i=0; i<N; i++){
         int s=0;
         for(int j=i; j<N; j++){
            s+=h[j];
            p[s]++;
         }
      }
      int q[1000*1500+1]={};
      for(int i=0; i<M; i++){
         int s=0;
         for(int j=i; j<M; j++){
            s+=w[j];
            q[s]++;
         }
      }

      int s=0;
      for(int i=0; i<1000*1500+1; i++){
         s+=p[i]*q[i];
      }

      cout<< s<< endl;
   }

   return 0;
}
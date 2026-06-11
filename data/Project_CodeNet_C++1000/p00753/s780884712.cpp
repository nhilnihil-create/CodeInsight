#include<iostream>

using namespace std;
const int K=300000;
int p[K];

void furui(){
   for(int i=0; i<K; i++) p[i]=1;
   p[0]=p[1]=0;
   for(int i=2; i*i<=K; i++){
      if(p[i]){
         for(int j=2; i*j<K; j++){
            p[i*j]=0;
         }
      }
   }
}

int main(){

   furui();
   while(1){
      int n;
      cin>> n;
      if(!n) break;

      int s=0;
      for(int i=0; i<=n; i++){
         s+=p[i];
      }
      int t=0;
      for(int i=0; i<=2*n; i++){
         t+=p[i];
      }

      cout<< t-s<< endl;
   }

   return 0;
}
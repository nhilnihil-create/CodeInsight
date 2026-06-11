#include <bits/stdc++.h>
using namespace std;

int main(){
   int N=0;
   cin >> N;
   vector<int> x(N);
   vector<int> y(N);
   int m=0;
   
   for(int i=0; i<N; i++){
       cin >> x.at(i) >> y.at(i);
   }

   int zmax=x.at(0)+y.at(0);
   int zmin=x.at(0)+y.at(0);
   int wmax=x.at(0)-y.at(0);
   int wmin=x.at(0)-y.at(0);


   for(int i=0; i<N; i++){
       if(zmax<x.at(i)+y.at(i)){
           zmax=x.at(i)+y.at(i);
       }

       if(zmin>x.at(i)+y.at(i)){
           zmin=x.at(i)+y.at(i);
       }
   }

   for(int i=0; i<N; i++){
       if(wmax<x.at(i)-y.at(i)){
           wmax=x.at(i)-y.at(i);
       }

       if(wmin>x.at(i)-y.at(i)){
           wmin=x.at(i)-y.at(i);
       }
   }

   m=max(zmax-zmin,wmax-wmin);
   cout << m << endl;
}
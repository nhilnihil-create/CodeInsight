#include<bits/stdc++.h>
using namespace std;
int main(void){
     int N,counter,D;
     cin>>N>>D;
     counter =0;
     for(int i=0;i<N;i++){
         long x,y;
         cin>>x>>y;
         if(D>=sqrt(x*x+y*y))counter++;
     }
     cout<<counter;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
  
 
int main(){
     int N;
     cin >> N;
     int d = N%10;
     N/=10;
     int v = 12;
     for(int i=1;i<=3;i+=1){
          if(N%10==d){
               cout << "Bad";
               v = 123;
               break;
               // exit(1);
          }
          d = N%10;
          N/=10;
     }
     if(v==12){
     cout<< "Good";
     }
}
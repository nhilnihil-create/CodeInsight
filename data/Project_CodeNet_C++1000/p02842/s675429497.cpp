#include <bits/stdc++.h>
using namespace std;

 int main(){
     int n;
      cin >> n;
      for(int i=0;i<n*2+10;i++){
          int to=i+(i*8)/100;
          if(to==n){
              cout << i << endl;
              break;
          }
          if(to>n){
              cout << ":(" << endl;
              break;
          }
      }
      return 0;
 }
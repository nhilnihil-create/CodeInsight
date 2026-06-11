#include<bits/stdc++.h>
using namespace std;
  
 
int main(){
     int N;
     cin >> N;
     int X;
     cin >> X;
     int d = 0;
     int ans = 1;
     for(int i=0;i<N;i+=1){
          int x;
          cin >> x;
          // cout << x << endl;
          
          d += x;
          if(d<=X){
               ans+=1;
          }
          
     }
     cout << ans << endl;
}

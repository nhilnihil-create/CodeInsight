#include<bits/stdc++.h>
using namespace std;
int main(){
     int t,n;
     cin>>n>>t;
     if(n==t){
        for(int i=0;i<n;i++){
            cout<<n;
        }
     }
      else if(n>t){
        for(int i=0;i<n;i++){
            cout<<t;
        }
      }
         else{
        for(int i=0;i<t;i++){
            cout<<n;
        }
         }
}


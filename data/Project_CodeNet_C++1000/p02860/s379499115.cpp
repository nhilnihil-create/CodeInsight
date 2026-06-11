#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
   int n;
   cin>>n;
   string s;
   cin>>s;
   if(n%2==1){
       cout<<"No";
   }
   else{
       for(int i=0;i<n/2;i++){
           
           if(s[i]!=s[i+n/2]){
               cout<<"No";
               exit(0);
           }
       }
       cout<<"Yes";
   }
}
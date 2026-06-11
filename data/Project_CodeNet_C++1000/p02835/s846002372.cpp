#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
 int a[3];
 int sum=0;
 for(int i=0;i<3;i++){
   cin>>a[i];
   sum+=a[i];
 } 
 if(sum>=22){
   cout<<"bust"<<endl;
 }
 else{
   cout<<"win"<<endl;
 }
}
#include<bits/stdc++.h>
using namespace std;
int main(){
 int n,m;
 int count=0;
 int sum=0;
  
 cin>>n>>m;
 int a[n];
  
 for(int i=0;i<n;i++){
   cin>>a[i];
   sum=sum+a[i];
 }
  
 for(int i=0;i<n;i++){
  if(a[i]*4*m>=sum){count++;}
 }
  
 if(count<m){
   cout<<"No"<<endl;
 }
 else if(count>=m){
   cout<<"Yes"<<endl;
 }
}

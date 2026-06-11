#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,c=0;
  cin>>n;
  int arr[n];
 for(int i=1;i<=n;i++){
   cin>>arr[i];
 }for(int i=1;i<=n;i=i+2){
   if(arr[i]%2!=0)
     c++;
 }cout<<c;
  return 0;
}
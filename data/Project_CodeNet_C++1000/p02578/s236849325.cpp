#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
  ll t;
 // cin>>t;
 // while(t--){
  ll a,b=0,c=0,d=0,e=0;
  cin>>a;
  ll arr[a];
  for(ll i=0;i<a;i++){cin>>arr[i];if(arr[i]>e){e=arr[i];}}
  for(ll i=0;i<a-1;i++){
    //d=d+1;
    if(arr[i+1]<arr[i]){c=c+(arr[i]-arr[i+1]);arr[i+1]=arr[i];}
   // cout<<c<<" ";
   // else{d=0;}
  }
  cout<<c;
 // }
}
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
typedef pair<int,int>P;
 
int main() {
  ll a,b,c;
  cin>>a>>b>>c;
  for(int i=0;i<b;i++){
    cout<<c<<" ";
  }
 for(int j=0;j<a-b;j++){
   if(j==(a-b-1)){
     if(c>2){
     cout<<c-1<<endl;
     }
     else{
       cout<<c+1<<endl;
     }
   }
   else {
     if(c>2){
   cout<<c-1<<" ";
     }
     else{
       cout<<c+1<<" ";
     }
   }
 }
}
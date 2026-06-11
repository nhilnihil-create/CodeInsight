#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
  ll t;
 // cin>>t;
 // while(t--){
  ll a,b=0,c=0,d=0,e=0;
  cin>>a>>b>>c;
    if(a%b!=0){
      d=(a/b)+1;
    }
    else{d=(a/b);}
    cout<<c*d<<endl;
 // }
}
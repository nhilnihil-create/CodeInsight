#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  long long int a,b,c;
  cin>>a>>b>>c;
  
  if((c-a-b)*(c-a-b)>4*a*b && c-a-b>0){
    cout<<"Yes";
  }else{
    cout<<"No";
  }



}
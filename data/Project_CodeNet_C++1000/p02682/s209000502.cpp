#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	ll a,b,c,k;
	cin>>a>>b>>c>>k;

  ll sum = 0;

  if( k > 0) {
      if( k > a){
        k = k-a;
        sum += a;
      }
      else{
        sum += k;
        cout<<sum<<"\n";
        return 0;
      }
  }

  
  if( k > 0) {
      if( k > b){
        k = k-b;
        sum += 0;
      }
      else{
        sum += 0;
        cout<<sum<<"\n";
        return 0;
      }
  }

  
  if( k > 0) {
      if( k > c){
        k = k-c;
        sum += c;
      }
      else{
        sum -= k;
        cout<<sum<<"\n";
        return 0;
      }
  }


  cout<<sum<<"\n";

  



	return 0;
}
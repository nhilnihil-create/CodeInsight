#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
  ll a,b;
  cin>>a>>b;
  bool imp=true;
  
  if(a<b){
  	for(int i=0;i<b;i++){
    	if(a+i==b-i){
        	cout<<i+a<<endl;
           imp=false;
          break;
       
        }
    }
  }
  
   else if(a>b){
  	for(int i=0;i<a;i++){
    	if(a-i==b+i){
        	cout<<i+b<<endl;
          imp=false;
          break;
       
        }
    }
  }
  if(imp)cout<<"IMPOSSIBLE"<<endl;
  //これ大-小/2+小で良くないか

}
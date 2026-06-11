#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main(){
	ll a,v;	cin>>a>>v;
 	ll b,w;	cin>>b>>w;
  	ll t;	cin>>t;
  if(v>w){
  	double temp=abs(b-a)*(1.0);
    double tm=v-w;
   	double p=(temp/tm);
    if(p<=t){
    	cout<<"YES"<<endl;
    }
    else{
    	cout<<"NO"<<endl;
    }
  }
  else{
  	cout<<"NO"<<endl;
  }
  return 0;
}
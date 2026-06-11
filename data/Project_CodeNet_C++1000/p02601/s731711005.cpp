#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,m;
  	cin>>a>>b>>c>>m;
  	while(b<=a){
    	b*=2;
      	m--;
    }
  	while(m--){
    	c*=2;
    }
  	c>b ? cout<<"Yes" : cout<<"No";
}
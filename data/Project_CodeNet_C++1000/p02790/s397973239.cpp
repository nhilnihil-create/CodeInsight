#include<bits/stdc++.h>
#define ll long long int
#define l(i,a,b) for(ll i=a;i<b;i++)
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	if(a<=b){
		l(i,0,b) cout<<a;
		cout<<"\n";
	}
	else{
		l(i,0,a) cout<<b;
		cout<<"\n";
	}
	
	
}
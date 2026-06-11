#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,k;
	cin>>a>>b>>c;
	cin>>k;
	while(k&&a>=b){
		b=b*2;
		k--;
	}
	while(k&&b>=c){
		c=c*2;
		k--;
	}
	if(a<b&&b<c)
	cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
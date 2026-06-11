#include<iostream>
using namespace std;
int main() {
	//a<b<c
	int a,b,c,k;
	cin>>a>>b>>c>>k;
	int idex=0;
	while(b<=a) {
		b*=2;
		idex++;
	}
	while(c<=b) {
		c*=2;
		idex++;
	}
	if(idex<=k) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
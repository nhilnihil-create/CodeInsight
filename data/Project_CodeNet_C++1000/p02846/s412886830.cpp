#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t1,t2,a1,a2,b1,b2;
int main() {
	cin>>t1>>t2;
	cin>>a1>>a2;
	cin>>b1>>b2;
	if(a1*t1+a2*t2>b1*t1+b2*t2) swap(a1,b1),swap(a2,b2);
	a1*=t1;a2*=t2;
	b1*=t1;b2*=t2;
	ll tota=a1+a2,totb=b1+b2;
//	cout<<"tota = "<<tota<<" totb = "<<totb<<'\n';
//	cout<<"a1 = "<<a1<<" a2 = "<<a2<<'\n';
//	cout<<"b1 = "<<b1<<" b2 = "<<b2<<'\n';
	if(tota<totb && a1<b1) {
//		cout<<"went here\n"; 
		cout<<"0";
		return 0;
	}
	if(tota==totb) {
		cout<<"infinity";
		return 0;
	}
	if((a1-b1)%(totb-tota))cout<<(a1-b1)/(totb-tota)*2+1<<'\n';
	else cout<<(a1-b1)/(totb-tota)*2<<'\n';
//	if()
	return 0;
}
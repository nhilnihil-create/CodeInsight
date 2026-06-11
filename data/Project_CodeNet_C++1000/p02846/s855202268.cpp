#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll t1,t2,a1,a2,b1,b2;
	cin>>t1>>t2;
	cin>>a1>>a2;cin>>b1>>b2;	
	ll x=a1*t1+a2*t2,y=b1*t1+b2*t2;
	if(x==y)cout<<"infinity"<<endl;
	else if((x>y&&a1<b1)||(x<y&&a1>b1)){
		ll t=(a1-b1)*t1;
		ll d=y-x;
		if(t%d!=0)cout<<t/d*2+1<<endl;
		else cout<<t/d*2<<endl;
	}
	else cout<<0<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
long long t1,t2,a1,a2,b1,b2,a,b,s,ret;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>t1>>t2;
	cin>>a1>>a2;
	cin>>b1>>b2;
	a=a1-b1;
	b=a2-b2;
	if(a<0){
		a=-a;
		b=-b;
	}
	s=a*t1+b*t2;
	if(s==0){
		cout<<"infinity"<<endl;
		return 0;
	}
	if(s>0){
		cout<<"0"<<endl;
		return 0;
	}
	if(s<0){
		ret=a*t1/(-s)+(-b)*t2/(-s);
		if((-b)*t2%(-s)==0LL)
			ret-=1LL;
		cout<<ret<<endl;
		return 0;
	}
	return 0;
}

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	double a,b,v,w,t;
	cin>>a>>v>>b>>w>>t;
	double  c,d,e;
	if(a>b){
		c=a-b;
	}else if(a<b){
		c=b-a;
	}
	if(c<0)c*=-1;
	d=v-w;
	if(d<=0){
		cout<<"NO"<<endl;
		return 0;
	}else{
		e=c/d;
	}
	if(ceil(e)<=t){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
#define endl "\n" 
#define ll long long 
#define sp " "
#define pi acos(-1)
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ll q=1;//cin>>q;
	while(q--){
		long double a,b,h,m,big,small,angle,c;cin>>a>>b>>h>>m;
		big =(h+m/60)*(pi/6);
		small=(m)*(pi/30);
		angle=cos(big-small);
		c=sqrt(a*a+b*b-2*a*b*angle);
		cout<<fixed<<setprecision(20)<<c<<endl;
	}
}
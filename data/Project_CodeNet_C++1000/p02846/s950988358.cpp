#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll t1,t2,a1,a2,b1,b2;
	cin>>t1>>t2>>a1>>a2>>b1>>b2;
	ll f1=a1-b1;ll f2=a2-b2;
	if(f1>0&&f2>0||f1<0&&f2<0){
		cout << 0;
		return 0;
	}
	f1=abs(f1);f2=abs(f2);
	ll dx1=t1*f1;
	ll dx2=t2*f2;
	if(dx1-dx2>0){
		cout << 0;
		return 0;
	}
	if(dx1==dx2){
		cout <<"infinity";
		return 0;
	}
	dx2=abs(dx2-dx1);
	ll cnt=(dx1+dx2-1)/dx2;
	ll ans=cnt*2;
	if(dx1%dx2!=0){
		ans--;
	}
	cout <<ans;
	// your code goes here
	return 0;
}
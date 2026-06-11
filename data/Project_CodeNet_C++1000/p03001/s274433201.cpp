#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll w,h,x,y;
	cin>>w>>h>>x>>y;
	cout<<h*w/2.0<<" ";
	if(x*2==w && y*2==h) cout<<1;
	else cout<<0;
}
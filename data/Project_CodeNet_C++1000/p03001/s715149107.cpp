#include <bits/stdc++.h>
using namespace std;
#define fx(x) fixed<<setprecision(x)
//give up
int main(){
	int a,b,x,y; cin>>a>>b>>x>>y;
	if(x+x==a&&y+y==b) cout<<fx(6)<<double(a)*double(b)/2<<" "<<1<<endl;
	else cout<<fx(6)<<double(a)*double(b)/2<<" "<<0<<endl;
}
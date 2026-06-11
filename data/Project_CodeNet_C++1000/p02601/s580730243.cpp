#include<bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
void solve(){
	int a,b,c,k;
	cin>>a>>b>>c;
	cin>>k;
	int x=0,y=0;
	if(a>=b){
		x=ceil((log(a/b)/log(2)));
		if(a>=b*pow(2,x))x++;
	}
	b*=pow(2,x);
	if(b>=c){
		y=ceil((log(b/c)/log(2)));
		if(b>=c*pow(2,y))y++;
	}
	//cout<<x<<" "<<y<<"\n";
	if(x+y>k)cout<<"No\n";
	else cout<<"Yes\n";	
}
int main(){
	FASTIO
//	int t;
//	cin>>t;
//	while(t--)solve();
	solve();
	return 0;
}

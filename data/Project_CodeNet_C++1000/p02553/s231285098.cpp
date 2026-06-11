#include<bits/stdc++.h>
using namespace std;
void solve(){
	long long a,b,c,d,x,y;
	cin>>a>>b>>c>>d;
	x=max(b*d,a*c);
	y=max(a*d,b*c);
	cout<<max(x,y);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
 
}
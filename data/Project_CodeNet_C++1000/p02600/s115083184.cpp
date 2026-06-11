#include<bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
void solve(){
	int n;
	cin>>n;
	if(n>=400&&n<600)cout<<8<<"\n";
	else if(n>=600&&n<800)cout<<"7\n";
	else if(n>=800&&n<1000)cout<<"6\n";
	else if(n>=1000&&n<1200)cout<<"5\n";
	else if(n>=1200&&n<1400)cout<<"4\n";
	else if(n>=1400&&n<1600)cout<<"3\n";
	else if(n>=1600&&n<1800)cout<<"2\n";
	else cout<<"1\n";
}
int main(){
	FASTIO
//	int t;
//	cin>>t;
//	while(t--)solve();
	solve();
	return 0;
}

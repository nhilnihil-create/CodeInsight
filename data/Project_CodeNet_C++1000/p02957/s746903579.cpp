#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
int main(){
	ll a,b; cin>>a>>b;
	if(a>b) swap(a,b);
	if((a+b)%2==1) cout<<"IMPOSSIBLE";
	else cout<<(a+b)/2;
}

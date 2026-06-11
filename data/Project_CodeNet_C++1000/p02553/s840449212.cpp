#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define ll long long

int main(){
#ifndef ONLINE_JUDGE
	freopen("C:\\Users\\User\\Documents\\input.txt","r",stdin);
#endif
	int T,i,j;
	ll a,b,c,d,res=0;
	cin>>a>>b>>c>>d;

	res=max(a*c,max(b*d,max(a*d,b*c)));
	printf("%lld\n",res);


		
		
	return 0;
}
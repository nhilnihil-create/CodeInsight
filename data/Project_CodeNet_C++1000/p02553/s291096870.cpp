#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int n1=(a*c),n2=(a*d);
	int n3=(b*c),n4=(b*d);
	int ans=max(max(n1,n2),max(n3,n4));
	cout<<ans;
    
    
    
    
	return 0;
}
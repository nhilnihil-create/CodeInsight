#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,k,ans;
	cin>>a>>b>>c>>k;
	if(k<=a) ans=k;
	else{
		if(k<=a+b) ans=a;
		else ans=a-(k-a-b);
	}
	cout<<ans;
	return 0;
}
